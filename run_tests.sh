#!/bin/bash

# Compile the tests and the library
g++ src/vector3.cpp src/tests/vector3_test.cpp -o vector3_test -std=c++17 -I include/

# Run the tests
./vector3_test

# Delete the executable
rm vector3_test
