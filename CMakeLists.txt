cmake_minimum_required(VERSION 3.14)
project(DeviceSimulation)

# Use C++17
set(CMAKE_CXX_STANDARD 17)

# Add include directory
include_directories(include)

# Add executable
add_executable(DeviceSim
    src/main.cpp
)
