#include "cairo-turtle.hpp"
#include <math.h> 
#include <iostream>


// === con/destructors ==============================================
/*
Init cairo turtle with default values
*/
CairoTurtle::CairoTurtle() :
    current_state_(0.0, 0.0, 0.0),
    start_state_(0.0, 0.0, 0.0),
    is_initialised_(false)
{
    // set default configuration
    configuration_ = {};
    surface_ = nullptr;
    cr_ = nullptr;
};

/*
Deconstructor for the cairo turtle
*/
CairoTurtle::~CairoTurtle() {

    //cleanup cairo
    cairo_destroy(cr_);
    cairo_surface_destroy(surface_);
}

// === configuration functions ======================================
void CairoTurtle::configure(const Configuration& configuration) {
    configuration_ = configuration;
}

void CairoTurtle::init() {

    if (is_initialised_) {
        // cleanup old turtle
        cairo_destroy(cr_);
        cairo_surface_destroy(surface_);
    }

    // initalisie cairo for drawing
    surface_ = cairo_image_surface_create(CAIRO_FORMAT_RGB24, configuration_.width_, configuration_.height_);
    cr_ = cairo_create(surface_);

    // background white and lines black for now
    cairo_set_source_rgb(cr_, 1, 1, 1);
    cairo_paint(cr_);
    cairo_set_source_rgb(cr_, 0, 0, 0);

    cairo_set_line_width(cr_, 1.0);
    
    is_initialised_ = true;
}


/*
Sets the start state so it will be possible to end the drawing without an extra line
*/
void CairoTurtle::set_start_state(State start_state) {
    start_state_ = start_state_;
}

// === state functions ==============================================
/*
Saves the current state
*/
void CairoTurtle::save_state() {
    states_.push(current_state_);
};

/*
Sets the current sate to last saved state
*/
void CairoTurtle::pop_state() {
    current_state_ = states_.top();
    states_.pop();
};

// === drawing functions ============================================
/*
Moves the current position without drawing a line
*/
void CairoTurtle::move_to(double x, double y) {
    current_state_.set_x(x);
    current_state_.set_y(y);

    cairo_move_to(cr_, x, y);
};

/*
Draws a line from the current position with the current direction
*/
void CairoTurtle::draw_line() {

    auto next_state = calculate_next_state(current_state_, configuration_.line_length_);
    cairo_line_to(cr_, next_state.get_x(), next_state.get_y());

    current_state_ = next_state;
};

/*
Draws a short line from the current position with the current direction
*/
void CairoTurtle::draw_short_line() {

    auto next_state = calculate_next_state(current_state_, configuration_.short_line_length_);
    cairo_line_to(cr_, next_state.get_x(), next_state.get_y());

    current_state_ = next_state;
};

/*
Calculates a right turn and sets the current state to the new direction
*/
void CairoTurtle::turn_right() {
    auto angle = current_state_.get_angle();

    // No need to normailize angle because the only use is with sin/cos
    angle += configuration_.turn_angle_;

    current_state_.set_angle(angle);
};

/*
Calculates a left turn and sets the current state to the new direction
*/
void CairoTurtle::turn_left() {
    auto angle = current_state_.get_angle();

    // No need to normailize angle because the only use is with sin/cos
    angle -= configuration_.turn_angle_;

    current_state_.set_angle(angle);
};

// === output/saving ============================================
/*
Saves the current drawing state to a png
*/
void CairoTurtle::save_to_png() {
    
    // when the path is closed and you are not on the start position it will draw a line form the end position to the start position
    // move to the start so it wont draw this line
    move_to(start_state_.get_x(), start_state_.get_y());
    cairo_close_path(cr_);
    cairo_stroke(cr_);

    cairo_surface_write_to_png(surface_, configuration_.export_filename_.c_str());
}

void CairoTurtle::view_result() {
    std::cout << "View result is not implemented - the data will be exported as png: " << configuration_.export_filename_ << std::endl;
    save_to_png();
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

    return {next_x, next_y, angle};
};