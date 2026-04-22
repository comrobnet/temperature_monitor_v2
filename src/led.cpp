#include "led.hpp"

#include <utility>

Led::Led(std::string name) : name_(std::move(name))
{
    // TODO: Initialize the GPIO according to hardware specifications
}

bool Led::Set(const bool on) {
    state_ = on;
    return true;
}

bool Led::Get() const {
    return state_;
}

const std::string& Led::Name() const {
    return name_;
}
