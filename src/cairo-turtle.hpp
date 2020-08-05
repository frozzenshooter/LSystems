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
public:

    // === con/destructors ==========================================
    CairoTurtle() :
        current_state_(0.0, 0.0, 0.0),
        start_state_(0.0, 0.0, 0.0)
    {
        //speichern der cairo pointer in unique pointer -> release um den raw pointer zu bekommen den man dann zum destroyen an cairo übergeben kann
        recording_surface_ = cairo_recording_surface_create(CAIRO_CONTENT_COLOR_ALPHA, NULL);
        cr_ = cairo_create(recording_surface_);

        // save the current state, because when you save it as a file you want to restore it
        cairo_save(cr_);

        // Paint the background white and set the color for drawing to black
        //TODO furter improvements can contain the dynamic setting of color
        cairo_set_source_rgb(cr_, 1, 1, 1);
        cairo_paint(cr_);
        cairo_set_source_rgb(cr_, 0, 0, 0);

        // get line width
        cairo_set_line_width(cr_, 1.0);

        // init the bounding box
        x_max_ = 0;
        x_min_ = 0;
        y_max_ = 0;
        y_min_ = 0;
    }

    ~CairoTurtle() {
        //cleanup cairo
        cairo_destroy(cr_);
        cairo_surface_destroy(recording_surface_);
    }

public:
    // === drawing functions ========================================
    void move() override {
        auto next_state = calculate_next_state(current_state_, 3.0);
        cairo_move_to(cr_, next_state.get_x(), next_state.get_y());
        current_state_ = next_state;

        // update the bouding box for later calculations
        updateBoundingValues(current_state_);
    }

    void draw() override {
        auto next_state = calculate_next_state(current_state_, 3.0);
        cairo_line_to(cr_, next_state.get_x(), next_state.get_y());
        current_state_ = next_state;

        // update the bouding box for later calculations
        updateBoundingValues(current_state_);
    }

    void turn_right() override {
        auto angle = current_state_.get_angle();

        // No need to normailize angle because the only use is with sin/cos
        angle += 60.0;

        current_state_.set_angle(angle);

        // update the bouding box for later calculations
        updateBoundingValues(current_state_);
    }

    void turn_left() override {
        auto angle = current_state_.get_angle();

        // No need to normailize angle because the only use is with sin/cos
        angle -= 60.0;

        current_state_.set_angle(angle);

        // update the bouding box for later calculations
        updateBoundingValues(current_state_);
    }

    // === output ============================================
    void save_to_png() {
        // when the path is closed and you are not on the start position it will draw a line form the end position to the start position
        // move to the start so it wont draw this line
        cairo_move_to(cr_, start_state_.get_x(), start_state_.get_y());
        cairo_close_path(cr_);
        cairo_stroke(cr_);
        cairo_restore(cr_);

        //double x0, y0, width, height;
        //cairo_recording_surface_ink_extents(recording_surface_, &x0, &y0, &width, &height);
        // Problem with the recording surface -> wont return the correct size data -> bounding box calcuaction done by hand

        // width and height calculated
        double calw = (x_max_ - x_min_);
        double calh = (y_max_ - y_min_);

        // std::cout << "Max(" << x_max_ << ", " << y_max_ << " ); Min(" << x_min_ << ", " << y_min_ << "); WH(" << calw << ", " << calh << ");"<< std::endl;

        // create an image surface to execute the recorded data
        cairo_surface_t* target = cairo_image_surface_create(CAIRO_FORMAT_RGB24, calw, calh);
        cairo_t* crt = cairo_create(target);

        // Translate the surface so that the lines will be in the covered area fo the image surface
        cairo_translate(crt, -x_min_, y_min_);

        // Paint the recorded commands to the image surface
        cairo_set_source_surface(crt, recording_surface_, 0, 0);
        cairo_paint(crt);

        //FURTHER IMPROVEMENT: SCALING -> PICTURES SIZE INCREASES VERY FAST

        auto t = cairo_surface_write_to_png(target, "export_file.png");

        std::cout << cairo_status_to_string(t) << std::endl;

        // cleanup the image surface
        cairo_destroy(crt);
        cairo_surface_destroy(target);
    }

private:

    // === calcualtions =============================================
    State calculate_next_state(State current_state, double line_length) {
        auto angle = current_state.get_angle();
        auto x_diff = sin(angle * 3.14159 / 180) * line_length;
        auto y_diff = cos(angle * 3.14159 / 180) * line_length;

        auto next_x = current_state.get_x() + x_diff;
        auto next_y = current_state.get_y() + y_diff;

        return { next_x, next_y, angle };
    }

    void updateBoundingValues(const State& state) {
        if (state.get_x() > x_max_) {
            x_max_ = state.get_x();
        }
        else if (state.get_x() < x_min_) {
            x_min_ = state.get_x();
        }

        if (state.get_y() > y_max_) {
            y_max_ = state.get_y();
        }
        else if (state.get_y() < y_min_) {
            y_min_ = state.get_y();
        }
    };
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