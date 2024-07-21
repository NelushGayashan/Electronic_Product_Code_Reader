#ifndef LCD_H
#define LCD_H

#include <string>

class LCD
{
public:
    void initialize();
    void display(const std::string &message);
};

#endif // LCD_H
