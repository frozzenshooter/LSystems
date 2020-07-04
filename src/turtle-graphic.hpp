#ifndef TURTLE_GRAPHIC_HPP
#define TURTLE_GRAPHIC_HPP

#include "configuration.hpp"

class TurtleGraphic {

public:

    //TODO why no pure virtual destructor?
    // === destructor ===============================================
    virtual ~TurtleGraphic(){};

    // === configuration functions ==================================
    virtual void configure(const Configuration& configuration) = 0;
    virtual void init() = 0;

    // === state functions ==========================================
    virtual void save_state() = 0;
    virtual void pop_state() = 0;

    // === drawing functions ========================================
    virtual void move_to(double x, double y) = 0;

    virtual void draw_line() = 0;
    virtual void draw_short_line() = 0;

    virtual void turn_right() = 0;
    virtual void turn_left() = 0;

    // === output/saving ============================================
    virtual void save_to_png() = 0;
    virtual void view_result() = 0;
};

#endif

