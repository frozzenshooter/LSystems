#ifndef TEST_TUTRLE_HPP
#define TEST_TUTRLE_HPP

#include <iostream>
#include "turtle.hpp"

/*
Implementation of the turtle interface, which will output the called functions via std::out
*/
class TestTurtle : public Turtle {
public:

    ~TestTurtle() override {};

    /*
    Prints the move command to std::cout
    */
    void move() noexcept override {
        std::cout << "[Draw-Call]: move" << std::endl;
    }

    /*
    Prints the draw command to std::cout
    */
    void draw() noexcept override {
        std::cout << "[Draw-Call]: draw" << std::endl;
    }

    /*
    Prints the turn_right command to std::cout
    */
    void turn_right() noexcept override {
        std::cout << "[Draw-Call]: turn_right" << std::endl;
    }

    /*
    Prints the turn_left command to std::cout
    */
    void turn_left() noexcept override {
        std::cout << "[Draw-Call]: turn_left" << std::endl;
    }
};
#endif