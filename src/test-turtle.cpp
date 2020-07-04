#include "test-turtle.hpp"

#include <iostream>

// === configuration functions ==================================
void TestTurtle::configure(const Configuration& configuration) {
    std::cout << "configure" << std::endl;
};

void TestTurtle::init() {
    std::cout << "init" << std::endl;
};

// === state functions ==========================================
void TestTurtle::save_state() {
    std::cout << "save_state" << std::endl;
};

void TestTurtle::pop_state() {
    std::cout << "pop_state" << std::endl;
};

// === drawing functions ========================================
void TestTurtle::move_to(double x, double y) {
    std::cout << "move_to: (" << x << ", "<< y << " )" << std::endl;
};

void TestTurtle::draw_line() {
    std::cout << "draw_line" << std::endl;
};

void TestTurtle::draw_short_line() {
    std::cout << "draw_short_line" << std::endl;
};

void TestTurtle::turn_right() {
    std::cout << "turn_right" << std::endl;
};

void TestTurtle::turn_left() {
    std::cout << "turn_left" << std::endl;
};

// === output/saving ============================================
void TestTurtle::save_to_png() {
    std::cout << "save_to_png" << std::endl;
}

void TestTurtle::view_result() {
    std::cout << "view_result" << std::endl;
}