#ifndef STATE_HPP
#define STATE_HPP

/*
The state represents the state of a turtle in a two dimensional coordinate system.

The state consists of a position with x and y coordinates and the current facing direction.
*/
class State {
public:

    State(double x_position, double y_position, double angle) : x_position_(x_position), y_position_(y_position), angle_(angle) {};

    void set_x(double x) noexcept {
        x_position_ = x;
    }

    void set_y(double y) noexcept {
        y_position_ = y;
    }

    void set_angle(double angle) noexcept {
        angle_ = angle;
    }

    double get_x() const noexcept {
        return x_position_;
    }

    double get_y() const noexcept {
        return y_position_;
    }

    double get_angle() const noexcept {
        return angle_;
    }

private:
    double x_position_;
    double y_position_;
    double angle_;
};

#endif