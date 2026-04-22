#ifndef LED_HPP
#define LED_HPP

#include <string>

// The LED class handles the setting of a single LED via GPIO
class Led {
public:
    // Initialize the mocked LED
    explicit Led(std::string name);

    // Set the LED state to on (true) and off (false)
    bool Set(bool on);

    // Get the LED state on (true) / off (false)
    bool Get() const;

    const std::string& Name() const;

private:
    std::string name_;
    bool state_{false};
};

#endif // LED_HPP
