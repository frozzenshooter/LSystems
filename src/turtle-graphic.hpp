#ifndef TURTLE_GRAPHIC_HPP
#define TURTLE_GRAPHIC_HPP

class TurtleGraphic {
public:

    //TODO why no pure virtual destructor?
    // === destructor ===============================================
    virtual ~TurtleGraphic() {};

    // === state functions ==========================================
    virtual void save_state() = 0;
    virtual void pop_state() = 0;

    // === drawing functions ========================================
    virtual void move_to(double x, double y) = 0;

    virtual void draw_line() = 0;
    virtual void draw_short_line() = 0;

    virtual void turn_right() = 0;
    virtual void turn_left() = 0;

    // Parameter packs to provide different configurations for every possible implementation 
    // https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/
};

#endif