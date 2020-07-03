#ifndef TEST_TUTRLE_HPP
#define TEST_TUTRLE_HPP

#include "TurtleGraphic.hpp"

class TestTurtle : public TurtleGraphic {

public:

    ~TestTurtle() {};

    // configuration
    void set_export_filename(std::string filename) override;
    void save_to_png() override;

    // state functions
    void save_state() override;

    void pop_state() override;

    // configuration functions
    void set_line_width(double width) override;

    void set_line_length(double length) override;

    void set_short_line_length(double length) override;

    void set_turn_angle(double degree) override;

    // drawing functions
    void move_to(double x, double y) override;

    void draw_line() override;

    void draw_short_line() override;

    void turn_right() override;

    void turn_left() override;
};
#endif
