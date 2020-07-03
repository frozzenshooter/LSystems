#include "cairo-turtle.hpp"
#include <math.h> 
#include <iostream>


// === con/destructors ==============================================
/*
* Init cairo turtle with default values
*/
CairoTurtle::CairoTurtle(int width, int height, const std::string& filename) :
    width_(width),
    height_(height),
    short_line_length_(0.5),
    line_length_(1.0),
    turn_angle_(45.0),
    filename_(filename),
    current_state_(0.0, 0.0, 0.0),
    start_state_(0.0, 0.0, 0.0)
{

    // initalisie cairo for drawing
    surface_ = cairo_image_surface_create(CAIRO_FORMAT_RGB24, width, height);
    cr_ = cairo_create(surface_);

    // background white and lines black for now
    cairo_set_source_rgb(cr_, 1, 1, 1);
    cairo_paint(cr_);
    cairo_set_source_rgb(cr_, 0, 0, 0);

    cairo_set_line_width(cr_, 1.0);
};

/*
* Deconstructor for the cairo turtle
*/
CairoTurtle::~CairoTurtle() {

    //cleanup cairo
    cairo_destroy(cr_);
    cairo_surface_destroy(surface_);
}

// === configuration functions ======================================
/*
* Sets the filename to export to
*/
void CairoTurtle::set_export_filename(std::string filename) {
    filename_ = filename;
}

/*
* Set the width of a line
*/
void CairoTurtle::set_line_width(double width) {
    cairo_set_line_width(cr_, width);
};

/*
* Set the length of a line
*/
void CairoTurtle::set_line_length(double length) {
    line_length_ = length;
};

/*
* Set the length of the short line
*/
void CairoTurtle::set_short_line_length(double length) {
    short_line_length_ = length;
};

/*
* Sets the turn angle
*/
void CairoTurtle::set_turn_angle(double degree) {
    turn_angle_ = degree;
};

/*
* Sets the start state so it will be possible to end the drawing without an extra line
*/
void CairoTurtle::set_start_state(State start_state) {
    start_state_ = start_state_;
}

// === state functions ==============================================
/*
* Saves the current state
*/
void CairoTurtle::save_state() {
    states_.push(current_state_);
};

/*
* Sets the current sate to last saved state
*/
void CairoTurtle::pop_state() {
    current_state_ = states_.top();
    states_.pop();
};

// === drawing functions ============================================
/*
* Moves the current position without drawing a line
*/
void CairoTurtle::move_to(double x, double y) {
    current_state_.set_x(x);
    current_state_.set_y(y);

    cairo_move_to(cr_, x, y);
};

/*
* Draws a line from the current position with the current direction
*/
void CairoTurtle::draw_line() {

    auto next_state = calculate_next_state(current_state_, line_length_);
    cairo_line_to(cr_, next_state.get_x(), next_state.get_y());

   // std::cout << "( " << next_state.get_x() << ", " << next_state.get_y() << ", " << next_state.get_angle() << " )" << std::endl;
    current_state_ = next_state;
};

/*
* Draws a short line from the current position with the current direction
*/
void CairoTurtle::draw_short_line() {

    auto next_state = calculate_next_state(current_state_, short_line_length_);
    cairo_line_to(cr_, next_state.get_x(), next_state.get_y());

    current_state_ = next_state;
};

/*
* Calculates a right turn and sets the current state to the new direction
*/
void CairoTurtle::turn_right() {
    auto angle = current_state_.get_angle();

    // No need to normailize angle because the only use is with sin/cos
    angle += turn_angle_;

    current_state_.set_angle(angle);
};

/*
* Calculates a left turn and sets the current state to the new direction
*/
void CairoTurtle::turn_left() {
    auto angle = current_state_.get_angle();

    // No need to normailize angle because the only use is with sin/cos
    angle -= turn_angle_;

    current_state_.set_angle(angle);
};

// === output/saving ============================================
/*
* Saves the current drawing state to a png
*/
void CairoTurtle::save_to_png() {
    move_to(start_state_.get_x(), start_state_.get_y());
    cairo_close_path(cr_);
    cairo_stroke(cr_);
    cairo_surface_write_to_png(surface_, filename_.c_str());
}

// === calcualtions =============================================
/*
* Calculates the next state when drawing a line with the current state and defined line length
*/
State CairoTurtle::calculate_next_state(State current_state, double line_length) {

    auto angle = current_state.get_angle();
    auto x_diff = sin(angle * 3.14159 / 180) * line_length;
    auto y_diff = cos(angle * 3.14159 / 180) * line_length;

    auto next_x = current_state.get_x() + x_diff;
    auto next_y = current_state.get_y() + y_diff;

    return {next_x, next_y, angle};
};