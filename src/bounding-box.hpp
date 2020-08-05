#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

class BoundingBox {
public:
    BoundingBox(double x_min, double x_max, double y_min, double y_max) : x_min_(x_min), x_max_(x_max), y_min_(y_min), y_max_(y_max) {}

private:

    double x_min_, x_max_, y_min_, y_max_;
};

#endif