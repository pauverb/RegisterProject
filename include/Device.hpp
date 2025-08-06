// include/Device.hpp
#ifndef DEVICE_HPP
#define DEVICE_HPP

class Device {
public:
    virtual void diagnose() const = 0;
    virtual void activateBit(int bit) = 0;
    virtual void deactivateBit(int bit) = 0;
    virtual ~Device() = default;
    
};

#endif