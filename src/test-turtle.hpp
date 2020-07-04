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
    void configure(const Configuration& configuration);
    void init();

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
};
#endif
