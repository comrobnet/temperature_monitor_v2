#include <cstring>

#include "eeprom.hpp"


Eeprom::Eeprom() {
    // initialize mock data
    mock_eeprom_[kEepromRevAddr] = 1;
    mock_eeprom_[0x01] = 'A';
    mock_eeprom_[0x02] = 'B';
    mock_eeprom_[0x03] = 'C';
    mock_eeprom_[0x04] = '1';
    mock_eeprom_[0x05] = '2';
    mock_eeprom_[0x06] = '3';
    mock_eeprom_[0x07] = '4';

    // TODO: Perform initialization actions depending on specific hardware and I2C
}

// Assign read eeprom data to device info members
bool Eeprom::ReadDeviceInfo() {
    std::uint8_t raw[1 + kEepromSerialLen];

    if (!Read_(kEepromRevAddr, raw, sizeof(raw))) {
        return false;
    }

    if (raw[0] != static_cast<std::uint8_t>(Revision::kRevA) &&
        raw[0] != static_cast<std::uint8_t>(Revision::kRevB)) {
        return false;
        }

    revision_ = static_cast<Revision>(raw[0]);
    serial_.assign(reinterpret_cast<const char*>(&raw[1]), kEepromSerialLen);
    initialized_ = true;
    return true;
}

// Read mock eeprom data and save it to the buffer
bool Eeprom::Read_(const std::uint16_t addr, std::uint8_t* buf, const std::size_t len) const {
    if (buf == nullptr) {
        return false;
    }

    if (static_cast<std::size_t>(addr) + len > kEepromSize) {
        return false;
    }

    std::memcpy(buf, &mock_eeprom_[addr], len);
    return true;
}