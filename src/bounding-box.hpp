#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

/*
The bounding box represents a rectangle, build up from two points. This rectangle will receive points in a two dimensional coordinate system.
It will strecht the rectangle to always include all of these points.

The bounding box offers to calculate the needed translation values, the width and the height to center or scale the coordinate system.
*/
class BoundingBox {
public:
    BoundingBox(double x_min = 0, double x_max = 0, double y_min = 0, double y_max = 0) : x_min_(x_min), x_max_(x_max), y_min_(y_min), y_max_(y_max) {}

    void set_x_max(double x_max) noexcept {
        x_max_ = x_max;
    }

    double get_x_max() const noexcept {
        return x_max_;
    }

    void set_x_min(double x_min) noexcept {
        x_min_ = x_min;
    }

    double get_x_min() const noexcept {
        return x_min_;
    }

    void set_y_max(double y_max) noexcept {
        y_max_ = y_max;
    }

    double get_y_max() const noexcept {
        return y_max_;
    }
    void set_y_min(double y_min) noexcept {
        y_min_ = y_min;
    }

    double get_y_min() const noexcept {
        return y_min_;
    }

    double get_width() const noexcept {
        return x_max_ - x_min_;
    }

    double get_height() const noexcept {
        return y_max_ - y_min_;
    }

    void update_x(double x) noexcept {
        if (x > x_max_) {
            x_max_ = x;
        }
        else if (x < x_min_) {
            x_min_ = x;
        }
    }

    void update_y(double y) noexcept {
        if (y > y_max_) {
            y_max_ = y;
        }
        else if (y < y_min_) {
            y_min_ = y;
        }
    }

    /*
    Returns the absolute value to translate into x direction
    */
    double get_translate_x() const noexcept {
        if (x_min_ < 0) {
            return -x_min_;
        }

        return x_min_;
    }

    /*
    Returns the absolute value to translate into y direction
    */
    double get_translate_y() const noexcept {
        if (y_min_ < 0) {
            return -y_min_;
        }

        return y_min_;
    }

private:

    double x_min_, x_max_, y_min_, y_max_;
};

#endif