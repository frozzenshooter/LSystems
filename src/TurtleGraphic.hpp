#ifndef TURTLE_GRAPHIC_HPP
#define TURTLE_GRAPHIC_HPP

class TurtleGraphic {

public:
    virtual ~TurtleGraphic(){};

    // state functions
    virtual void save_state() = 0;
    virtual void pop_state() = 0;

    // configuration functions
    virtual void set_line_width(float width) = 0;
    virtual void set_line_length(float length) = 0;
    virtual void set_short_line_length(float length) = 0;
    virtual void set_turn_angle(float degree) = 0;

    // drawing functions
    virtual void move_to(const int x, const int y) = 0;

    virtual void draw_line() = 0;
    virtual void draw_short_line() = 0;

    virtual void turn_right() = 0;
    virtual void turn_left() = 0;
};

#endif

