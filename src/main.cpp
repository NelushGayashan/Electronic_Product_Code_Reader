#include "EPR.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <boost/asio.hpp>

int main()
{
    boost::asio::io_service io_service;
    EPR epr(io_service);

    // Initialize EPR system
    epr.initialize();

    // Start the EPR system
    epr.start();

    // Simulate running time
    std::this_thread::sleep_for(std::chrono::seconds(10)); // Run for 10 seconds

    // Stop the EPR system
    epr.stop();

    return 0;
}
