#include "test-turtle.hpp"

#include <iostream>

// === configuration functions ==================================
void TestTurtle::configure() {
    std::cout << "[Turtle]: configure" << std::endl;
};

void TestTurtle::init() {
    std::cout << "[Turtle]: init" << std::endl;
};

// === state functions ==========================================
void TestTurtle::save_state() {
    std::cout << "[Draw-Call]: save_state" << std::endl;
};

void TestTurtle::pop_state() {
    std::cout << "[Draw-Call]: pop_state" << std::endl;
};

// === drawing functions ========================================
void TestTurtle::move_to(double x, double y) {
    std::cout << "[Draw-Call]: move_to: (" << x << ", "<< y << " )" << std::endl;
};

void TestTurtle::draw_line() {
    std::cout << "[Draw-Call]: draw_line" << std::endl;
};

void TestTurtle::draw_short_line() {
    std::cout << "[Draw-Call]: draw_short_line" << std::endl;
};

void TestTurtle::turn_right() {
    std::cout << "[Draw-Call]: turn_right" << std::endl;
};

void TestTurtle::turn_left() {
    std::cout << "[Draw-Call]: turn_left" << std::endl;
};

// === output/saving ============================================
bool TestTurtle::save_to_png() {
    std::cout << "[Turtle]: save_to_png" << std::endl;
    return true;
}

bool TestTurtle::view_result() {
    std::cout << "[Turtle]: view_result" << std::endl;
    return true;
}