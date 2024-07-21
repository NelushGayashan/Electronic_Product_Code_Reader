#include "RFID.h"
#include <boost/asio.hpp>
#include <iostream>

RFID::RFID(boost::asio::io_service &io_service, const std::string &port)
    : serialPort(io_service, port) {}

void RFID::initialize()
{
    try
    {
        serialPort.set_option(boost::asio::serial_port_base::baud_rate(9600));
        std::cout << "RFID Initialized" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed to initialize RFID: " << e.what() << std::endl;
    }
}

void RFID::startReading()
{
    try
    {
        if (serialPort.is_open())
        {
            boost::asio::write(serialPort, boost::asio::buffer("START\n"));
            std::cout << "RFID Reading Started" << std::endl;
        }
        else
        {
            std::cerr << "Serial port not open" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed to send start reading command: " << e.what() << std::endl;
    }
}

bool RFID::isReadingComplete() const
{
    try
    {
        if (serialPort.is_open())
        {
            boost::asio::read_until(serialPort, response, "COMPLETE\n");
            std::istream is(&response);
            std::string line;
            std::getline(is, line);
            return line.find("COMPLETE") != std::string::npos;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed to check reading status: " << e.what() << std::endl;
    }
    return false;
}

std::string RFID::getData() const
{
    try
    {
        if (serialPort.is_open())
        {
            boost::asio::write(serialPort, boost::asio::buffer("READ\n"));
            boost::asio::read_until(serialPort, response, "\n");
            std::istream is(&response);
            std::string data;
            std::getline(is, data);
            return data;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed to get RFID data: " << e.what() << std::endl;
    }
    return "";
}
