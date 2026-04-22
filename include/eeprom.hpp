#ifndef EEPROM_HPP
#define EEPROM_HPP

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>

constexpr std::size_t kEepromSize = 256;
constexpr std::uint16_t kEepromRevAddr = 0x00;
constexpr std::uint16_t kEepromSerialAddr = 0x01;
constexpr std::size_t kEepromSerialLen = 7;

// Define hardware revisions for the temperature sensor (Rev-A / Rev-B)
enum class Revision : std::uint8_t {
    kRevA = 0,
    kRevB = 1
};

// Class defining EEPROM object with functions to read the device info
class Eeprom {
public:
    // Initialize mock eeprom data
    Eeprom();

    // Assigned the read data to the revision and serial number members
    bool ReadDeviceInfo();

    [[nodiscard]] bool IsInitialized() const { return initialized_; }
    [[nodiscard]] Revision GetRevision() const { return revision_; }
    [[nodiscard]] const std::string& GetSerial() const { return serial_; }

private:
    // Read the data from the mocked eeprom
    bool Read_(std::uint16_t addr, std::uint8_t* buf, std::size_t len) const;

    bool initialized_{false};
    Revision revision_{Revision::kRevA};
    std::string serial_{};

    std::array<std::uint8_t, kEepromSize> mock_eeprom_{};
};

#endif // EEPROM_HPP