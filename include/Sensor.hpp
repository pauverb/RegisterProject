#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "Device.hpp"
#include "Register.hpp"
#include <cstdint>
#include <bitset>
#include <iostream>

class Sensor : public Device {
    Register<int8_t> reg;

public:
    Sensor() {
        reg.write(0b00001111);
    }

    void diagnose() const override {
        std::cout << "Sensor read: " << std::bitset<8>(reg.read()) << std::endl;
    }

    void activateBit(int bit) override {
        reg.setBit(bit);
        if (reg.isBitSet(bit)) {
            std::cout << "Sensor bit " << bit << " activated!" << std::endl;
        }
    }

    void deactivateBit(int bit) override {
        reg.clearBit(bit);
        if (!reg.isBitSet(bit)) {
            std::cout << "Sensor bit " << bit << " deactivated!" << std::endl;
        }
    }

    int8_t getValue() const {
        return reg.read();
    }

    ~Sensor() override = default;
};

#endif