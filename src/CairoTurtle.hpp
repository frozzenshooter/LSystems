#ifndef CAIRO_TUTRLE_HPP
#define CAIRO_TUTRLE_HPP

#include <string>
#include <stack>
#include <cairo.h>
#include "TurtleGraphic.hpp"
#include "State.hpp"


class CairoTurtle : public TurtleGraphic {

private:
    double normalize_angle(double angle);
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
    std::stack<State> states_;

    cairo_surface_t* surface_;
    cairo_t* cr_;
};
#endif
