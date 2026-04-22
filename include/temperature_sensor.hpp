#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP

#include <cstdint>

// Parent temperature sensor class, reading the temperature via ADC and converting the temperature to °C
class TemperatureSensor {
public:
    virtual ~TemperatureSensor() = default;

    // Return the raw ADC value of the temperature sensor (MOCK)
    [[nodiscard]] virtual std::uint16_t ReadAdc() const = 0;

    // Return the temperature measured by the sensor measured in Celsius
    [[nodiscard]] virtual float ReadCelsius() const = 0;
};

// Child class for Revision A of the sensor
class RevATemperatureSensor final : public TemperatureSensor {
public:
    RevATemperatureSensor() = default; // TODO: implement custom initializer based on hardware specifications
    [[nodiscard]] std::uint16_t ReadAdc() const override;

    // Rev-A has a resolution of 1 degree Celsius per digit. For example, a value of 10 corresponds to 10 °C
    [[nodiscard]] float ReadCelsius() const override;
};

// Child class for Revision B of the sensor
class RevBTemperatureSensor final : public TemperatureSensor {
public:
    RevBTemperatureSensor() = default; // TODO: implement custom initializer based on hardware specifications
    [[nodiscard]] std::uint16_t ReadAdc() const override;

    // Rev-B has a resolution of 0.1 degree Celsius per digit. For example, a value of 100 corresponds to 10 °C
    [[nodiscard]] float ReadCelsius() const override;
};

#endif // TEMPERATURE_SENSOR_HPP
