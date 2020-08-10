#ifndef TURTLE_HPP
#define TURTLE_HPP

/*
Base class for a turtle, which at least supports the general commands
*/
class Turtle {
public:
    virtual ~Turtle() {};

    /*
    Moves one step into the facing direction (without drawing)
    */
    virtual void move() = 0;

    /*
    Draws a line one step into the facing direction
    */
    virtual void draw() = 0;

    /*
    Changes the facing direction about an determined angle to the right
    */
    virtual void turn_right() = 0;

    /*
    Changes the facing direction about an determined angle to the left
    */
    virtual void turn_left() = 0;
};
#endif