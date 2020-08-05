#ifndef CAIRO_TUTRLE_HPP
#define CAIRO_TUTRLE_HPP

#include <string>
#include <stack>
#include <cairo.h>
#include "State.hpp"
#include "Turtle.hpp"
#include "bounding-box.hpp"

constexpr double MATH_PI = 3.14159265358979323846 ;
/*
* Class which uses the cairo graphics lib to implement turtle graphics behaviour
     //TODO furter improvements can contain the dynamic setting of color

     TODO usage erklären -> man kann nicht mehrfach zeichnen bei dieser implementierung

             //FURTHER IMPROVEMENT: SCALING -> PICTURES SIZE INCREASES VERY FAST
*/
class CairoTurtle : public Turtle {
public:

    CairoTurtle() :
        line_length_(3.0),
        line_width_(1.0),
        angle_(60.0),
        bounding_box_(0.0, 0.0, 0.0, 0.0),
        current_state_(0.0, 0.0, 0.0),
        start_state_(0.0, 0.0, 0.0)
    {
        // Initalize cairo recording surface
        recording_surface_ = cairo_recording_surface_create(CAIRO_CONTENT_COLOR_ALPHA, NULL);
        cr_ = cairo_create(recording_surface_);

        // Save the current state - able to restore it by the saving process
        cairo_save(cr_);

        // Paint the background white and set the color for drawing to black
        cairo_set_source_rgb(cr_, 1, 1, 1);
        cairo_paint(cr_);
        cairo_set_source_rgb(cr_, 0, 0, 0);

        // Set line width
        cairo_set_line_width(cr_, line_width_);
    }

    ~CairoTurtle() {

        // Cleanup cairo data
        cairo_destroy(cr_);
        cairo_surface_destroy(recording_surface_);
    }

public:

    // Overrides
    void move() override {

        auto next_state = calculate_next_state(current_state_);

        cairo_move_to(cr_, next_state.get_x(), next_state.get_y());
        current_state_ = next_state;

        // update the bouding box for later calculations
        updateBoundingValues(current_state_);
    }

    void draw() override {
        auto next_state = calculate_next_state(current_state_);

        cairo_line_to(cr_, next_state.get_x(), next_state.get_y());
        current_state_ = next_state;

        // update the bouding box for later calculations
        updateBoundingValues(current_state_);
    }

    void turn_right() override {
        auto angle = current_state_.get_angle();

        // No need to normalize angle because the only use is with sin/cos
        angle += angle_;

        current_state_.set_angle(angle);
    }

    void turn_left() override {
        auto angle = current_state_.get_angle();

        // No need to normalize angle because the only use is with sin/cos
        angle -= angle_;

        current_state_.set_angle(angle);
    }

    // Additonal functionality

    void set_line_lenght(double lenght) {
        line_length_ = lenght;
    }

    void set_line_width(double width) {
        line_width_ = width;
    }

    void set_turning_angle(double angle) {
        angle_ = angle;
    }

    void save_to_png(const std::string& filename) {

        // when the path is closed and you are not on the start position it will draw a line form the end position to the start position
        // move to the start so it wont draw this line
        cairo_move_to(cr_, start_state_.get_x(), start_state_.get_y());
        cairo_close_path(cr_);
        cairo_stroke(cr_);

        cairo_restore(cr_);

        // Normaly cairo provides a function, which will calculate the bounding box, but it returned only wrong values
        // therefore a implementation with a custom bounding box is implemented
        //
        // double x0, y0, width, height;
        // cairo_recording_surface_ink_extents(recording_surface_, &x0, &y0, &width, &height);

        // create an image surface to execute the recorded data
        cairo_surface_t* target = cairo_image_surface_create(CAIRO_FORMAT_RGB24, bounding_box_.get_width(), bounding_box_.get_height());
        cairo_t* crt = cairo_create(target);

        // Translate the surface so that the lines will be in the covered area fo the image surface
        cairo_translate(crt, bounding_box_.get_translate_x(), bounding_box_.get_translate_y());

        // Paint the recorded commands to the image surface
        cairo_set_source_surface(crt, recording_surface_, 0, 0);
        cairo_paint(crt);

        cairo_surface_write_to_png(target, filename.c_str());
        // auto error = cairo_surface_write_to_png(target, filename);
        // std::cout << cairo_status_to_string(t) << std::endl;

        // cleanup the image surface
        cairo_destroy(crt);
        cairo_surface_destroy(target);
    }

private:

    /*
    Calculate the next state from a given state
    */
    State calculate_next_state(State state) {

        auto angle = state.get_angle();
        auto x_diff = sin(angle * MATH_PI / 180) * line_length_;
        auto y_diff = cos(angle * MATH_PI / 180) * line_length_;

        auto next_x = state.get_x() + x_diff;
        auto next_y = state.get_y() + y_diff;

        return { next_x, next_y, angle };
    }

    /*
    Updates the values in the bouding box
    */
    void updateBoundingValues(const State& state) {
        bounding_box_.update_x(state.get_x());
        bounding_box_.update_y(state.get_y());
    };


    // Configuration data
    double line_length_;
    double line_width_;
    double angle_;

    // State of the turtle
    BoundingBox bounding_box_;

    State current_state_;
    State start_state_;
    std::stack<State> states_;

    // Cairo data
    cairo_surface_t* recording_surface_;
    cairo_t* cr_;
};
#endif