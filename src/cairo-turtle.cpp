#include "cairo-turtle.hpp"
#include <math.h>
#include <iostream>

// === con/destructors ==============================================
/*
Init cairo turtle with default values
*/
CairoTurtle::CairoTurtle() :
    current_state_(0.0, 0.0, 0.0),
    start_state_(0.0, 0.0, 0.0)
{
    surface_ = cairo_recording_surface_create(CAIRO_CONTENT_COLOR_ALPHA, NULL);
    cr_ = cairo_create(surface_);

    // background white and lines black for now
    cairo_set_source_rgb(cr_, 1, 1, 1);
    cairo_paint(cr_);
    cairo_set_source_rgb(cr_, 0, 0, 0);
    cairo_set_line_width(cr_, 1.0);
};

/*
Deconstructor for the cairo turtle
*/
CairoTurtle::~CairoTurtle() {
    //cleanup cairo
    cairo_destroy(cr_);
    cairo_surface_destroy(surface_);
}

/*
TODO: IS THIS NEEDED?
*/
void CairoTurtle::reset() {
    cairo_destroy(cr_);
    cairo_surface_destroy(surface_);
    states_.empty();

    surface_ = cairo_recording_surface_create(CAIRO_CONTENT_COLOR_ALPHA, NULL);
    cr_ = cairo_create(surface_);

    cairo_set_source_rgb(cr_, 1, 1, 1);
    cairo_paint(cr_);
    cairo_set_source_rgb(cr_, 0, 0, 0);

    cairo_set_line_width(cr_, 1.0);
}

/*
Sets the start state so it will be possible to end the drawing without an extra line
*/
void CairoTurtle::set_start_state(State start_state) {
    start_state_ = start_state_;
}

// === drawing functions ============================================
/*
Moves the current position without drawing a line
*/
void CairoTurtle::move() {

        auto next_state = calculate_next_state(current_state_, 3.0);
        cairo_move_to(cr_, next_state.get_x(), next_state.get_y());
        current_state_ = next_state;    
};

/*
Draws a line from the current position with the current direction
*/
void CairoTurtle::draw() {

        auto next_state = calculate_next_state(current_state_, 3.0);
        cairo_line_to(cr_, next_state.get_x(), next_state.get_y());
        current_state_ = next_state;
    
};

/*
Calculates a right turn and sets the current state to the new direction
*/
void CairoTurtle::turn_right() {

        auto angle = current_state_.get_angle();

        // No need to normailize angle because the only use is with sin/cos
        angle += 60.0;

        current_state_.set_angle(angle);
    
};

/*
Calculates a left turn and sets the current state to the new direction
*/
void CairoTurtle::turn_left() {

        auto angle = current_state_.get_angle();

        // No need to normailize angle because the only use is with sin/cos
        angle -= 60.0;

        current_state_.set_angle(angle);
    
};

// === output/saving ============================================
/*
Saves the current drawing state to a png
*/
void CairoTurtle::save_to_png() {

    // when the path is closed and you are not on the start position it will draw a line form the end position to the start position
    // move to the start so it wont draw this line
    cairo_move_to(cr_, start_state_.get_x(), start_state_.get_y());
    cairo_close_path(cr_);
    cairo_stroke(cr_);
    //double x0, y0, width, height;
    //cairo_recording_surface_ink_extents(surface_, &x0, &y0, &width, &height);
    //auto sf2 = cairo_surface_create_similar_image(surface_, CAIRO_FORMAT_RGB24, width, height);
    auto t = cairo_surface_status(surface_);
    std::cout << t << std::endl;
    cairo_surface_write_to_png(surface_, "export_file.png");
}

// === calcualtions =============================================
/*
Calculates the next state when drawing a line with the current state and defined line length
*/
State CairoTurtle::calculate_next_state(State current_state, double line_length) {
    auto angle = current_state.get_angle();
    auto x_diff = sin(angle * 3.14159 / 180) * line_length;
    auto y_diff = cos(angle * 3.14159 / 180) * line_length;

    auto next_x = current_state.get_x() + x_diff;
    auto next_y = current_state.get_y() + y_diff;

    return { next_x, next_y, angle };
};