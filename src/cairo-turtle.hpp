#ifndef CAIRO_TUTRLE_HPP
#define CAIRO_TUTRLE_HPP

#include <cairo.h>
#include <string>
#include "State.hpp"
#include "bounding-box.hpp"
#include "Turtle.hpp"

constexpr double CAIRO_PI = 3.14159265358979323846;

/*
This class is a simple implementation of the turtle class using the graphics library cairo.

The reset function is provided if the turtle is used multiple types. If reset isn't called the turtle will include further draw calls in the already existing path.

    //TODO furter improvements can contain the dynamic setting of color

    // TODO: ASSIGMENT / COPY CONST / ETC LÖSCHEN - nicht benötigt

    //FURTHER IMPROVEMENT: SCALING -> PICTURES SIZE INCREASES VERY FAST
*/
class CairoTurtle : public Turtle {
public:

    CairoTurtle() :
        line_length_(3.0),
        line_width_(1.0),
        angle_(60.0),
        bounding_box_(0.0, 0.0, 0.0, 0.0),
        current_state_(0.0, 0.0, 0.0)
    {
        init();
    }

    ~CairoTurtle() override {
        // Cleanup cairo data
        cairo_destroy(cr_);
        cairo_surface_destroy(recording_surface_);
    }

    // Overrides
    void move() override {
        calculate_next_state(current_state_);

        cairo_move_to(cr_, current_state_.get_x(), current_state_.get_y());

        // update the bouding box for later calculations
        updateBoundingValues(current_state_);
    }

    void draw() override {
        calculate_next_state(current_state_);

        cairo_line_to(cr_, current_state_.get_x(), current_state_.get_y());

        // update the bouding box for later calculations
        updateBoundingValues(current_state_);
    }

    void turn_right() override {
        auto angle = current_state_.get_angle();

        // No need to normalize (force range between 0 -360) angle because the only use is with sin/cos
        angle += angle_;

        current_state_.set_angle(angle);
    }

    void turn_left() override {
        auto angle = current_state_.get_angle();

        // No need to normalize (force range between 0 -360) angle because the only use is with sin/cos
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

    void reset() {
        // delete old data
        cairo_destroy(cr_);
        cairo_surface_destroy(recording_surface_);

        // reset turtle states
        bounding_box_.set_x_min(0);
        bounding_box_.set_x_max(0);
        bounding_box_.set_y_min(0);
        bounding_box_.set_y_max(0);
        current_state_ = { 0.0, 0.0, 0.0 };

        init();
    }

    void save_to_png(const std::string& filename) {
        // when the path is closed and you are not on the start position it will draw a line form the end position to the start position
        // move to the start so it wont draw this line
        cairo_move_to(cr_, 0.0, 0.0);
        cairo_close_path(cr_);
        cairo_stroke(cr_);

        cairo_restore(cr_);

        // Normaly cairo provides a function, which will calculate the bounding box, but it returned only wrong values
        // therefore a implementation with a custom bounding box is implemented
        //
        // double x0, y0, width, height;
        // cairo_recording_surface_ink_extents(recording_surface_, &x0, &y0, &width, &height);

        // create an image surface to execute the recorded data

        //TODO double to int conversion here evt explizit lösen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        cairo_surface_t* target = cairo_image_surface_create(CAIRO_FORMAT_RGB24, bounding_box_.get_width(), bounding_box_.get_height());
        cairo_t* crt = cairo_create(target);

        // Translate the surface so that the lines will be in the covered area fo the image surface
        cairo_translate(crt, std::round(bounding_box_.get_translate_x()), std::round(bounding_box_.get_translate_y()));

        // Paint the recorded commands to the image surface
        cairo_set_source_surface(crt, recording_surface_, 0, 0);
        cairo_paint(crt);

        auto errorcode = cairo_surface_write_to_png(target, filename.c_str());

        // cleanup the image surface
        cairo_destroy(crt);
        cairo_surface_destroy(target);

        if (errorcode != CAIRO_STATUS_SUCCESS) {
            throw new std::runtime_error("Saving process failed.");
        }
    }

private:

    void init() {
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

    /*
    Calculate the next state from a given state 
    
    
    TODO: DONT CREATE A NEW STATE ALL THE TIME -> JUST SET THE VALUES
    */
    void calculate_next_state(State& state) {
        auto angle = state.get_angle();
        auto x_diff = sin(angle * CAIRO_PI / 180) * line_length_;
        auto y_diff = cos(angle * CAIRO_PI / 180) * line_length_;

        auto next_x = state.get_x() + x_diff;
        auto next_y = state.get_y() + y_diff;

        state.set_x(next_x);
        state.set_y(next_y);

        return;
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

    // Cairo data
    cairo_surface_t* recording_surface_;
    cairo_t* cr_;
};
#endif