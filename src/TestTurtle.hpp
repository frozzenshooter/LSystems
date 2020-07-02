#ifndef TEST_TUTRLE_HPP
#define TEST_TUTRLE_HPP

#include "TurtleGraphic.hpp"

class TestTurtle : public TurtleGraphic {

public:

    ~TestTurtle() {};

    // state functions
    void save_state() override;

    void pop_state() override;

    // configuration functions
    void set_line_width(float width) override;

    void set_line_length(float length) override;

    void set_short_line_length(float length) override;

    void set_turn_angle(float degree) override;

    // drawing functions
    void move_to(const int x, const int y) override;

    void draw_line() override;

    void draw_short_line() override;

    void turn_right() override;

    void turn_left() override;

};
#endif
