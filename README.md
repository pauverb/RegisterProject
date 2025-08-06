# Embedded Bit Control Simulation

This project simulates a simple embedded system with a `Sensor` and an `Actuator`, each controlled via an 8-bit register. It shows bit-level manipulation, diagnostics, and basic timing.

## Features

- Activate and deactivate individual bits in a register
- Diagnose current bit states for both the sensor and actuator
- Simulate a timed control loop with clear diagnostic output
- Modular design using `Sensor`, `Actuator`, and `Register` classes

## Project Structure

- main.cpp – Entry point for the simulation
- Register.hpp – Core bit manipulation logic
- Sensor.hpp – Sensor behavior and diagnostics
- Actuator.hpp – Actuator behavior and diagnostics

## How to Build

Make sure you have a C++17-compatible compiler.

g++ -std=c++17 main.cpp Sensor.cpp Actuator.cpp Register.cpp -o bit_sim
./bit_sim

## Sample Output

Starting a simple testing...
Cycle 1:
Activating bit 0
Sensor bit 0 activated!
Bit 0 successfully activated!
Sensor read: 00001111
Actuator active: 00000001
...
Test loop completed.

### Output Explanation

The program runs a 4-cycle loop:
- In each cycle:
  - A specific bit (from 0 to 3) is activated in both the sensor and actuator.
  - The sensor and actuator report their current state.
  - Starting from the second cycle, the previously activated bit is deactivated.
- The Sensor::read() function returns a fixed value (00001111), while the actuator reflects the actual active bits.
- A short delay (500 milliseconds) simulates time between cycles.
