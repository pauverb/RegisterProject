#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include "Sensor.hpp"
#include "Actuator.hpp"

int main() {
    auto sensor = std::make_unique<Sensor>();
    auto actuator = std::make_unique<Actuator>();

    std::cout << "Starting a simple testing..." << std::endl;

    for (int cycle = 0; cycle < 4; ++cycle) {
        std::cout << "Cycle " << cycle + 1 << ":\n";

        int bitIndex = cycle % 8; // Use bit index, not bitmask

        std::cout << "Activating bit " << bitIndex << "\n";
        try {
            sensor->activateBit(bitIndex);
            actuator->activateBit(bitIndex);
        } catch (const std::out_of_range& e) {
            std::cerr << "Activation failed: " << e.what() << std::endl;
        }

        sensor->diagnose();
        actuator->diagnose();

        if (cycle > 0) {
            int prevBitIndex = (cycle - 1) % 8;
            std::cout << "Deactivating bit " << prevBitIndex << "\n";
            try {
                sensor->deactivateBit(prevBitIndex);
                actuator->deactivateBit(prevBitIndex);
            } catch (const std::out_of_range& e) {
                std::cerr << "Deactivation failed: " << e.what() << std::endl;
            }
        }

        std::cout << "-----------------------------\n";
        std::this_thread::sleep_for(std::chrono::microseconds(500));
    }

    std::cout << "Test loop completed." << std::endl;
    return 0;
}