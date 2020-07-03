#ifndef STATE_HPP
#define STATE_HPP

class State {

public:
    State(double x_position, double y_position, double angle) : x_position_(x_position), y_position_(y_position), angle_(angle) {};

    void set_x(double x) {
        x_position_ = x;
    }

    void set_y(double y) {
        y_position_ = y;
    }

    void set_angle(double angle) {
        angle_ = angle;
    }

    double get_x() const {
        return x_position_;
    }

    double get_y() const {
        return y_position_;
    }

    double get_angle() const {
        return angle_;
    }

private:
    double x_position_;
    double y_position_;
    double angle_;
};

#endif

