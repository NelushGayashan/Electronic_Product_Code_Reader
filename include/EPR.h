#ifndef EPR_H
#define EPR_H

#include "RFID.h"
#include "LCD.h"
#include "Keypad.h"
#include <boost/asio.hpp>

class EPR
{
public:
    EPR(boost::asio::io_service &io_service);
    void initialize();
    void start();
    void stop();

private:
    RFID rfid;
    LCD lcd;
    Keypad keypad;
    bool isActive;
};

#endif // EPR_H
