#ifndef COMMAND_MAPPING_ITERATOR_HPP
#define COMMAND_MAPPING_ITERATOR_HPP

#include "turtle.hpp"

/*
The command mapping iterator represents an output iterator. This iterator receives chars and calls the mapped turtle function.

This is a sample implementation for the use togheter with a L-system. 

*/
class CommandMappingIterator {
public:

    CommandMappingIterator(Turtle& turtle) noexcept : turtle_(std::addressof(turtle)) {}

    CommandMappingIterator& operator=(const char& c) {
        handle(c);
        return *this;
    }

    CommandMappingIterator& operator=(char&& c) {
        handle(c);
        return *this;
    }

    CommandMappingIterator& operator*() noexcept {
        return *this;
    }

    CommandMappingIterator& operator++() noexcept {
        return *this;
    }

    CommandMappingIterator operator++(int) noexcept {
        return *this;
    }

private:
    void handle(char c) {
        switch (c)
        {
        case 'F':
            turtle_->draw();
            break;
        case '-':
            turtle_->turn_left();
            break;
        case 'f':
            turtle_->move();
            break;
        case '+':
            turtle_->turn_right();
            break;
        default:
            // do nothing
            break;
        }
    }

    // only save pointer to allow different turtle implementations
    Turtle* turtle_;
};
#endif