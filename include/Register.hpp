#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <stdexcept>

template <typename T>
class Register {
    T value;

public:
    Register() : value(T{}) {}

    T read() const {
        return value;
    }

    void write(T val) {
        value = val;
    }

    void setBit(int bit) {
        if (bit >= 8 || bit < 0) {
            throw std::out_of_range("Bit index out of range");
        }
        value |= (1 << bit);
    }

    void clearBit(int bit) {
        value &= ~(1 << bit);
    }

    bool isBitSet(int bit) const {
        return value & (1 << bit);
    }
};

#endif