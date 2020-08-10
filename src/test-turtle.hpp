#ifndef TEST_TUTRLE_HPP
#define TEST_TUTRLE_HPP

#include <iostream>
#include "turtle.hpp"

/*
Implementation of the turtle ingterface, which will output the called functions via std::out
*/
class TestTurtle : public Turtle {
public:

    ~TestTurtle() override {};

    /*
    Prints the move command to std::cout
    */
    void move() override {
        std::cout << "[Draw-Call]: move" << std::endl;
    }

    /*
    Prints the draw command to std::cout
    */
    void draw() override {
        std::cout << "[Draw-Call]: draw" << std::endl;
    }

    /*
    Prints the turn_right command to std::cout
    */
    void turn_right() override {
        std::cout << "[Draw-Call]: turn_right" << std::endl;
    }

    /*
    Prints the turn_left command to std::cout
    */
    void turn_left() override {
        std::cout << "[Draw-Call]: turn_left" << std::endl;
    }
};
#endif