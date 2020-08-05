#ifndef TURTLE_HPP
#define TURTLE_HPP

class Turtle {
public:
    virtual ~Turtle() {};
    virtual void move() = 0;
    virtual void draw() = 0;
    virtual void turn_right() = 0;
    virtual void turn_left() = 0;
};

#endif