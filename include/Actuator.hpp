#ifndef ACTUATOR_HPP
#define ACTUATOR_HPP

#include <iostream>
#include <cstdint>
#include <bitset>
#include "Device.hpp"
#include "Register.hpp"

class Actuator:public Device{
    Register<int8_t> reg;
    public:
    Actuator() {
        reg.write(0b00000000);
    }

    void diagnose() const override {
        std::cout << "Actuator active: " <<std::bitset<8>(reg.read()) << std::endl;
    };

    void activateBit(int bit){
        reg.setBit(bit);
       if( reg.isBitSet(bit)){
        std::cout << "Bit " << bit << " succesfully activated !" << std::endl;
       }
    }

    void deactivateBit(int bit){
        reg.clearBit(bit);
        if (!reg.isBitSet(bit)) {
            std::cout << "Bit " << bit << " successfully deactivated!" << std::endl;
        }
    }

    int8_t getValue() const {
        return reg.read();
    }
   
};

#endif