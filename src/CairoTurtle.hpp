#ifndef CAIRO_TUTRLE_HPP
#define CAIRO_TUTRLE_HPP

#include "TurtleGraphic.hpp"

class CairoTurtle : public TurtleGraphic {

public:

    ~CairoTurtle() {};

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
