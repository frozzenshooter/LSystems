#ifndef CAIRO_TUTRLE_HPP
#define CAIRO_TUTRLE_HPP

#include <string>
#include <stack>
#include <cairo.h>
#include "State.hpp"
#include "Turtle.hpp"

/*
* Class which uses the cairo graphics lib to implement turtle graphics behaviour
*/
class CairoTurtle : public Turtle {
private:
    // === calcualtions =============================================
    State calculate_next_state(State current_state, double line_length);
    void updateBoundingValues(const State& state);

public:
    // === drawing functions ========================================
    void move() override;
    void draw() override;
    void turn_right() override;
    void turn_left() override;


    // === con/destructors ==========================================
    CairoTurtle();
    ~CairoTurtle();

    // === output ============================================
    void save_to_png();

private:

    // === states ===================================================
    State current_state_;
    State start_state_;
    std::stack<State> states_;

    // === cairo pointers ===========================================
    cairo_surface_t* recording_surface_;
    cairo_t* cr_;

    //bounding

    double x_max_, x_min_, y_max_, y_min_;
};
#endif