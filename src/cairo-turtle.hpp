#ifndef CAIRO_TUTRLE_HPP
#define CAIRO_TUTRLE_HPP

#include <string>
#include <stack>
#include <cairo.h>
#include "turtle-graphic.hpp"
#include "State.hpp"


/*
* Class which uses the cairo graphics lib to implement turtle graphics behaviour
*/
class CairoTurtle : public TurtleGraphic {

private:
    // === calcualtions =============================================
    State calculate_next_state(State current_state, double line_length);

public:

    // === con/destructors ==========================================
    CairoTurtle();
    ~CairoTurtle();

    // === configuration functions ==================================
    void configure() override;
    void init() override;

    void set_start_state(State start_state);

    // === state functions ==========================================
    void save_state() override;
    void pop_state() override;

    // === drawing functions ========================================
    void move_to(double x, double y) override;

    void draw_line() override;
    void draw_short_line() override;

    void turn_right() override;
    void turn_left() override;

    // === output/saving ============================================
    bool save_to_png() override;
    bool view_result() override;

private:

    // === configuration data =======================================
    bool is_initialised_;
    //Configuration configuration_;

    // === states ===================================================
    State current_state_;
    State start_state_;
    std::stack<State> states_;

    // === cairo pointers ===========================================
    cairo_surface_t* surface_;
    cairo_t* cr_;
};
#endif
