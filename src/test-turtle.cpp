#include "test-turtle.hpp"

#include <iostream>

// === drawing functions ========================================
void TestTurtle::move() {
    std::cout << "[Draw-Call]: move" << std::endl;
};

void TestTurtle::draw() {
    std::cout << "[Draw-Call]: draw" << std::endl;
};

void TestTurtle::turn_right() {
    std::cout << "[Draw-Call]: turn_right" << std::endl;
};

void TestTurtle::turn_left() {
    std::cout << "[Draw-Call]: turn_left" << std::endl;
};