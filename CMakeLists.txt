cmake_minimum_required(VERSION 3.10)
project(EPR_Project)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED COMPONENTS system)

include_directories(include ${Boost_INCLUDE_DIRS})

add_executable(epr_program
    src/main.cpp
    src/RFID.cpp
    src/LCD.cpp
    src/Keypad.cpp
    src/EPR.cpp
)

target_link_libraries(epr_program ${Boost_LIBRARIES})
