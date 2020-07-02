#include "TestTurtle.hpp"

#include <iostream>

// state functions
void TestTurtle::save_state() {
    std::cout << "save_state" << std::endl;
};
    
void TestTurtle::pop_state() {
    std::cout << "pop_state" << std::endl;
};

// configuration functions
void TestTurtle::set_line_width(float width) {
    std::cout << "set_line_width" << width << std::endl;
};

void TestTurtle::set_line_length(float length) {
    std::cout << "set_line_length: " << length << std::endl;
};

void TestTurtle::set_short_line_length(float length) {
    std::cout << "set_short_line_length: " << length << std::endl;
};

void TestTurtle::set_turn_angle(float degree) {
    std::cout << "set_turn_angle: " << degree << std::endl;
};

// drawing functions
void TestTurtle::move_to(const int x, const int y) {
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
