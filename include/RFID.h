#ifndef RFID_H
#define RFID_H

#include <string>
#include <boost/asio.hpp>

class RFID
{
public:
    RFID(boost::asio::io_service &io_service, const std::string &port);
    void initialize();
    void startReading();
    bool isReadingComplete() const;
    std::string getData() const;

private:
    boost::asio::serial_port serialPort;
    mutable boost::asio::streambuf response;
};

#endif // RFID_H
