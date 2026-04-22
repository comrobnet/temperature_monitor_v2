cmake_minimum_required(VERSION 3.30)
project(temperature_monitor_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(temperature_monitor
    src/main.cpp
    src/eeprom.cpp
    src/led.cpp
    src/temperature_sensor.cpp
    src/temperature_monitor.cpp
)

target_include_directories(temperature_monitor PRIVATE include)
