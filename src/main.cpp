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

        int currentbit = 1 << (cycle % 8); // Rotate through bits 0–7

        std::cout << "Activating bit " << (cycle % 8) << "\n";
        sensor->activateBit(currentbit);
        actuator->activateBit(currentbit);

        sensor->diagnose();
        actuator->diagnose();

        if (cycle > 0) {
            int prevBit = 1 << ((cycle - 1) % 8);
            std::cout << "Deactivating bit " << ((cycle - 1) % 8) << "\n";
            sensor->deactivateBit(prevBit);
            actuator->deactivateBit(prevBit);
        }

        std::cout << "-----------------------------\n";
        std::this_thread::sleep_for(std::chrono::microseconds(500));
    }

    std::cout << "Test loop completed." << std::endl;
    return 0;
}