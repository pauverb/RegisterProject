// Thix to do later with this project 
// at the end split into header files *.hpp and main.cpp
// also try cmake ; maybe even with previuos file
#include <iostream>
#include <cstdint>
#include <bitset>
#include <vector>
#include <memory>


// == will be moved to another file 
template <typename T>
class Register {
    T value;
    public:
    Register(): value(T{}) {} // constructor
    T read() const {         // why const ? const means that this method doesnt modify the object
        return value;
    }
    void write(T Val){
        value = Val;
    }
     
    void setBit(int bit){
        if(bit>8 || bit < 0){
            throw std::out_of_range("Bit index out of range");
        }
        value |= (1<<bit);
    }
    void clearBit(int bit){
        value &= ~(1<<bit);
    }
    bool isBitSet(int bit) const {
        return value & (1 << bit);
    }
};

//==

class Device{   /// Base class
    public:
    virtual void diagnose() const = 0;
    virtual ~Device(){}
};


class Sensor:public Device{ // derives class[Sensor] from base class[Device]
    Register<int8_t> reg; // here type is an object 
    public:
    Sensor() {
        reg.write(0b00001111); // initial value if not set
    } 
    void diagnose() const override{
        std :: cout << "Sensor read: " << std::bitset<8>(reg.read()) << std::endl;
    }

};

int main() {    
    std::vector<std::unique_ptr<Device>> devices; // Device is an abstact class need to be stored pointers

    devices.push_back(std::make_unique<Sensor>());
    devices.push_back(std::make_unique<Sensor>());

    for(const auto& device : devices){
        device->diagnose();
    }
    return 0;
}