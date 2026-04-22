#include "temperature_sensor.hpp"

std::uint16_t RevATemperatureSensor::ReadAdc() const {
    // TODO: Implement revision hardware specific ADC read
    return 10;
}

float RevATemperatureSensor::ReadCelsius() const {
    // TODO: Real implementation might also have offsets or non-linearity
    return static_cast<float>(ReadAdc()) * 1.0f;
}

std::uint16_t RevBTemperatureSensor::ReadAdc() const {
    // TODO: Implement revision hardware specific ADC read
    return 100;
}

float RevBTemperatureSensor::ReadCelsius() const {
    // TODO: Real implementation might also have offsets or non-linearity
    return static_cast<float>(ReadAdc()) * 0.1f;
}
