#include <chrono>
#include <iostream>
#include <thread>

#include "temperature_monitor.hpp"

int main() {
    using clock = std::chrono::steady_clock;
    using namespace std::chrono_literals;

    constexpr auto kLoopPeriod = 100us;

    TemperatureMonitor monitor;

    if (!monitor.Init()) {
        std::cerr << "Failed to initialize temperature monitor\n";
        return 1;
    }

    while (true) {
        const auto loop_start = clock::now();

        monitor.Step();
        // monitor.PrintStatus();

        const auto loop_end = clock::now();

        if (const auto elapsed = loop_end - loop_start; elapsed < kLoopPeriod) {
            std::this_thread::sleep_for(kLoopPeriod - elapsed);
        }
    }

    return 0;
}