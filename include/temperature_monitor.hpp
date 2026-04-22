#ifndef TEMPERATURE_MONITOR_HPP
#define TEMPERATURE_MONITOR_HPP

#include <memory>

#include "eeprom.hpp"
#include "led.hpp"
#include "temperature_sensor.hpp"


class TemperatureMonitor {
public:
    // Construct Monitor and initialize LEDs
    TemperatureMonitor();

    // Initialize the device by reading the device information from the EEPROM
    bool Init();
    // Perform one step in the update loop, reading the temperature and updating the LEDs accordingly
    void Step();
    // Print the current status of the device
    void PrintStatus() const;

private:
    Eeprom eeprom_;
    std::unique_ptr<TemperatureSensor> sensor_;
    Led green_;
    Led yellow_;
    Led red_;
};

#endif // TEMPERATURE_MONITOR_HPP
