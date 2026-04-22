# Temperature Monitor (C++)

This project implements a simple temperature monitor in C++ using mocked hardware interfaces. It is intended to run on a PC for demonstration purposes, while following an embedded-style architecture.

## Overview

The software simulates an embedded temperature monitoring system with the following components:

- **EEPROM**: stores hardware revision and serial number
- **Temperature sensor**: provides a mock ADC-based temperature reading
- **LEDs**: indicate the current temperature range

The monitor reads the device information from EEPROM, selects the correct sensor behavior for the detected hardware revision, and updates the LEDs accordingly.

## Design

The C version was refactored into a C++ project using object-oriented design:

- **`Eeprom`**  
  Encapsulates EEPROM access and stores the loaded revision and serial number.

- **`TemperatureSensor`**  
  Abstract base class for temperature sensors.

- **`RevATemperatureSensor` / `RevBTemperatureSensor`**  
  Concrete sensor classes implementing revision-specific ADC and temperature conversion behavior.

- **`Led`**  
  Represents an individual LED with its own state.

- **`TemperatureMonitor`**  
  Coordinates EEPROM reading, sensor selection, temperature evaluation, and LED control.

## Hardware Revisions

Two hardware revisions are supported:

- **Rev-A**: ADC resolution is **1.0 °C per digit**
- **Rev-B**: ADC resolution is **0.1 °C per digit**

The mocked EEPROM contains:

- revision: `0` or `1`
- serial number: `"ABC1234"`

## LED Behavior

The LEDs indicate the temperature range:

- **Green**: operational temperature
- **Yellow**: warning temperature
- **Red**: critical temperature

## Timing

The main loop is executed with a target period of **100 µs**.  
Each iteration measures its own execution time and sleeps for the remaining time.

## Project Structure

- `src/main.cpp` - program entry point and main loop
- `src/eeprom.cpp` - mocked EEPROM implementation
- `src/temperature_sensor.cpp` - temperature sensor classes
- `src/led.cpp` - LED implementation
- `src/temperature_monitor.cpp` - monitor logic
- `include/` - public header files

## Build

Example with CMake:

```sh
cmake -S . -B build
cmake --build build