# Electronic_Product_Code_Reader# Electronic Product Code Reader (EPR) Project

## Overview

This project implements an Electronic Product Code Reader (EPR) using an 8051 microcontroller. The EPR is designed to read passive RFID tags and display the Electronic Product Code (EPC) values on an LCD screen. The system also includes a keypad for user interaction.

## Project Structure

The project is organized into the following directories and files:
```bash
EPR_Project/
│
├── include/
│ ├── RFID.h
│ ├── LCD.h
│ ├── Keypad.h
│ └── EPR.h
│
├── src/
│ ├── RFID.cpp
│ ├── LCD.cpp
│ ├── Keypad.cpp
│ ├── EPR.cpp
│ └── main.cpp
│
├── build/
│
├── CMakeLists.txt
│
└── README.md
```


## Components

### RFID Module

The RFID module is responsible for reading EPC values from passive RFID tags. It uses the Boost.Asio library for serial communication.

### LCD Display

The LCD display is used to show the EPC values read from the RFID tags. 

### Keypad

The keypad is used for user interaction to start and stop the EPR system.

### EPR System

The EPR system integrates the RFID module, LCD display, and keypad to create a complete EPC reader.

## Dependencies

- [Boost C++ Libraries](https://www.boost.org/) (specifically Boost.Asio for serial communication)

## Building the Project

1. Ensure you have [CMake](https://cmake.org/) and [Boost](https://www.boost.org/) installed on your system.

2. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/EPR_Project.git
   cd EPR_Project
   ```
3. Create a build directory and navigate to it:

   ``` bash
   mkdir build
   cd build
   ```

4. Run CMake to generate the build files:

   ```bash
   cmake ..
   ```

 5. Build the project:

   ```bash
    make
   ```

## Running the Project

  1. After building the project, you will find the executable in the build directory.

  2. Run the executable:

   ```bash
    ./epr_program
   ```

## Code Explanation

**main.cpp**
The main entry point of the program initializes and starts the EPR system, runs it for 10 seconds, and then stops it.

**EPR.cpp and EPR.h**
The EPR class integrates the RFID module, LCD display, and keypad. It manages the initialization, starting, and stopping of the system.

**RFID.cpp and RFID.h**
The RFID class handles the initialization and communication with the RFID module using Boost.Asio for serial communication.

**LCD.cpp and LCD.h**
The LCD class handles the initialization and displaying of messages on the LCD screen.

**Keypad.cpp and Keypad.h**
The Keypad class handles the initialization and reading of key presses from the keypad.

## Notes

- Adjust the serial port and baud rate settings in RFID.cpp to match your hardware configuration.
- The RFID, LCD, and Keypad classes use placeholder code for demonstration purposes. Replace these with actual implementation details based on your hardware.

## License

This project is licensed under the MIT License. See the LICENSE file for details.