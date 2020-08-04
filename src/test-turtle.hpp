#ifndef TEST_TUTRLE_HPP
#define TEST_TUTRLE_HPP

#include "turtle.hpp"

/*
* Class to test the turtle behaviour - it will output the called functions via std::out
*/
class TestTurtle : public Turtle {
public:
    // === con/deconstructor ========================================
    ~TestTurtle() {};

    // === drawing functions ========================================
    void move() override;
    void draw() override;
    void turn_right() override;
    void turn_left() override;
};
#endif