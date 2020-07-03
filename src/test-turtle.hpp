#ifndef TEST_TUTRLE_HPP
#define TEST_TUTRLE_HPP

#include "turtle-graphic.hpp"

/*
* Class to test the turtle behaviour - it will output the called functions via std::out
*/
class TestTurtle : public TurtleGraphic {

public:
    // === con/deconstructor ========================================
    ~TestTurtle() {};

    // === configuration functions ==================================
    void set_export_filename(std::string filename) override;
    void set_line_width(double width) override;
    void set_line_length(double length) override;
    void set_short_line_length(double length) override;
    void set_turn_angle(double degree) override;

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
    void save_to_png() override;
};
#endif
