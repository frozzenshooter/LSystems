#ifndef CAIRO_TUTRLE_HPP
#define CAIRO_TUTRLE_HPP

#include <string>
#include <stack>
#include <cairo.h>
#include "turtle-graphic.hpp"
#include "State.hpp"


class CairoTurtle : public TurtleGraphic {

private:
    State calculate_next_state(State current_state, double line_length);

public:

    CairoTurtle(int width, int height, const std::string& filename);

    ~CairoTurtle();

    // configuration functions
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

    void set_start_state(State start_state);

    // drawing functions
    void move_to(double x, double y) override;

    void draw_line() override;

    void draw_short_line() override;

    void turn_right() override;

    void turn_left() override;

private:

    // configuration data
    int width_;
    int height_;
    double short_line_length_;
    double line_length_;
    double turn_angle_;
    std::string filename_;

    // states
    State current_state_;
    State start_state_;
    std::stack<State> states_;

    cairo_surface_t* surface_;
    cairo_t* cr_;
};
#endif
