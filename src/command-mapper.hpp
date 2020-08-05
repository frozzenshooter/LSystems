#ifndef COMMAND_MAPPER_HPP
#define COMMAND_MAPPER_HPP

#include "turtle.hpp"

// TODO: wihtout a template -> problem in the handle funtcion -> just offer another iterator afor another type
// Rename and describe in paper
class CommandMappingIterator {

public: 

    explicit CommandMappingIterator(Turtle& turtle) noexcept : turtle_(std::addressof(turtle)) {}

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
    void handle(const char& c) {
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

    // hier eine referenz weil sonst der destructor augerfuen wird -> evt mit pointer übergeben, damit man nicht den kopierkonstruiert und abbaut
    // TODO: andere Lösung wäre ein pointer -> damit kann man dann auch dne dynamischen polymorophismus garantieren-> HIer nochmals auführlich beschreiben
    Turtle* turtle_;
};
#endif