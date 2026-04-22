#include "temperature_monitor.hpp"

#include <iostream>
#include <memory>

// TODO: LED initialization could be moved to init if needed
TemperatureMonitor::TemperatureMonitor()
    : green_("Green"), yellow_("Yellow"), red_("Red") {}

bool TemperatureMonitor::Init() {
    if (!eeprom_.ReadDeviceInfo()) {
        return false;
    }

    switch (eeprom_.GetRevision()) {
        case Revision::kRevA:
            sensor_ = std::make_unique<RevATemperatureSensor>();
            break;
        case Revision::kRevB:
            sensor_ = std::make_unique<RevBTemperatureSensor>();
            break;
        default:
            return false;
    }

    return true;
}

void TemperatureMonitor::Step() {
    if (!sensor_) {
        return;
    }

    // TODO: Sensor data might require filtering or dead band to avoid LED flickering
    const float temperature = sensor_->ReadCelsius();

    green_.Set(false);
    yellow_.Set(false);
    red_.Set(false);

    // A bit more memory costly because of the floats; could also do boundary adjustment as in C example
    if (temperature >= 5.0f && temperature < 85.0f) {
        green_.Set(true);
    } else if (temperature >= 85.0f && temperature < 105.0f) {
        yellow_.Set(true);
    } else {
        red_.Set(true);
    }
}

void TemperatureMonitor::PrintStatus() const {
    if (!sensor_) {
        return;
    }

    std::cout << "Serial: " << eeprom_.GetSerial() << "\n";
    std::cout << "Revision: "
              << (eeprom_.GetRevision() == Revision::kRevA ? "RevA" : "RevB") << "\n";
    std::cout << "Temperature: " << sensor_->ReadCelsius() << " C\n";
    std::cout << "LED state: "
              << "G=" << (green_.Get() ? "ON" : "OFF") << " "
              << "Y=" << (yellow_.Get() ? "ON" : "OFF") << " "
              << "R=" << (red_.Get() ? "ON" : "OFF") << "\n";
}
