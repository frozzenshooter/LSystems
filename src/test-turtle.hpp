#ifndef TEST_TUTRLE_HPP
#define TEST_TUTRLE_HPP

#include <iostream>
#include "turtle.hpp"

/*
* Class to test the turtle behaviour - it will output the called functions via std::out
*/
class TestTurtle : public Turtle {
public:
    // === con/deconstructor ========================================
    ~TestTurtle() override {};

    // === drawing functions ========================================
    void move() override {
        std::cout << "[Draw-Call]: move" << std::endl;
    }

    void draw() override {
        std::cout << "[Draw-Call]: draw" << std::endl;
    }

    void turn_right() override {
        std::cout << "[Draw-Call]: turn_right" << std::endl;
    }

    void turn_left() override {
        std::cout << "[Draw-Call]: turn_left" << std::endl;
    }
};
#endif