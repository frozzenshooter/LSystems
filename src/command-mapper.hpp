#ifndef COMMAND_MAPPER_HPP
#define COMMAND_MAPPER_HPP

#include "turtle.hpp"

template<typename Predecessor>
class CommandMappingIterator {

public: 

    explicit CommandMappingIterator(CairoTurtle& turtle) noexcept : turtle_(turtle) {}

    void set_turtle(const Turtle& turtle) {
        turtle_ = turtle;
    }

    CommandMappingIterator& operator=(const Predecessor& predecessor) {
        handle(predecessor);
        return *this;
    }

    CommandMappingIterator& operator=(Predecessor&& predecessor) {
        handle(predecessor);
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
    void handle(const Predecessor& c) {
        switch (c)
        {
        case 'F':
            turtle_.draw();
            break;
        case '-':
            turtle_.turn_left();
            break;
        case 'f':
            turtle_.move();
            break;
        case '+':
            turtle_.turn_right();
            break;
        default:
            // do nothing
            break;
        }
    }

    // hier eine referenz weil sonst der destructor augerfuen wird -> evt mit pointer übergeben, damit man nicht den kopierkonstruiert und abbaut
    CairoTurtle& turtle_;
};
#endif



//// CLASS TEMPLATE back_insert_iterator
//template <class _Container>
//class back_insert_iterator { // wrap pushes to back of container as output iterator
//public:
//    using iterator_category = output_iterator_tag;
//    using value_type = void;
//    using difference_type = void;
//    using pointer = void;
//    using reference = void;
//
//    using container_type = _Container;
//
//    explicit back_insert_iterator(_Container& _Cont) noexcept /* strengthened */ : container(_STD addressof(_Cont)) {}
//
//    back_insert_iterator& operator=(const typename _Container::value_type& _Val) {
//        container->push_back(_Val);
//        return *this;
//    }
//
//    back_insert_iterator& operator=(typename _Container::value_type&& _Val) {
//        container->push_back(_STD move(_Val));
//        return *this;
//    }
//
//    _NODISCARD back_insert_iterator& operator*() noexcept /* strengthened */ {
//        return *this;
//    }
//
//    back_insert_iterator& operator++() noexcept /* strengthened */ {
//        return *this;
//    }
//
//    back_insert_iterator operator++(int) noexcept /* strengthened */ {
//        return *this;
//    }
//
//protected:
//    _Container* container; // pointer to container
//};