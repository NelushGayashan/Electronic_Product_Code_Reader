#include "EPR.h"
#include <iostream>
#include <chrono>
#include <thread>

EPR::EPR(boost::asio::io_service& io_service)
    : rfid(io_service, "/dev/ttyUSB0"), isActive(false) {}

void EPR::initialize() {
    rfid.initialize();
    lcd.initialize();
    keypad.initialize();
}

void EPR::start() {
    isActive = true;
    lcd.display("EPR Started");
    rfid.startReading();

    while (isActive) {
        if (rfid.isReadingComplete()) {
            std::string data = rfid.getData();
            lcd.display("EPC: " + data);
        }
        // Optionally add a sleep or delay
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleep for 1 second
    }
}

void EPR::stop() {
    isActive = false;
    lcd.display("EPR Stopped");
}
