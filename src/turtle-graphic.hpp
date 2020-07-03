#ifndef TURTLE_GRAPHIC_HPP
#define TURTLE_GRAPHIC_HPP

#include <string>

class TurtleGraphic {

public:
    virtual ~TurtleGraphic(){};

    // configuration
    virtual void set_export_filename(std::string filename) = 0;
    virtual void save_to_png() = 0;

    // state functions
    virtual void save_state() = 0;
    virtual void pop_state() = 0;

    // configuration functions
    virtual void set_line_width(double width) = 0;
    virtual void set_line_length(double length) = 0;
    virtual void set_short_line_length(double length) = 0;
    virtual void set_turn_angle(double degree) = 0;

    // drawing functions
    virtual void move_to(double x, double y) = 0;

    virtual void draw_line() = 0;
    virtual void draw_short_line() = 0;

    virtual void turn_right() = 0;
    virtual void turn_left() = 0;
};

#endif

