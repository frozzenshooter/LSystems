#ifndef TURTLE_GRAPHIC_HPP
#define TURTLE_GRAPHIC_HPP

class TurtleGraphic {

public:

    virtual TurtleGraphic(const int start_postion_x, const int start_postion_y, const int start_heading) = 0;

    virtual void save_state() = 0;
    virtual void pop_state() = 0;

    virtual void set_line_width() = 0;

    virtual void move_to(const int x, const int y) = 0;

    virtual void draw_line() = 0;
    virtual void draw_line(const int lenght, const int degree) = 0;

    virtual void rotate(const int degree) = 0;
};

#endif

