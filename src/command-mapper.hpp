#ifndef COMMAND_MAPPER_HPP
#define COMMAND_MAPPER_HPP

#include "turtle.hpp"

template<typename Predecessor, typename OutputIterator>
class CommandMapper {

public:
    //TODO why no pure virtual destructor?
    virtual ~CommandMapper() {};

    virtual OutputIterator handle() = 0;

    vooid set_turtle(const Turtle& turtle) {
        turtle_ = turtle;
    }

private:

    Turtle turtle_;
};


// IDEE zuweisen erlauben und sobald ein increment gemacht wird, wird der alte wert ausgewertet -> aber problem beim letzten wert -> wie wird dieser gehandhabt
// bzw wie wird die korrekte funktion aufgerufen??
// zwischenklasse, die beim zuwesien eines wertes direkt den Turtle command aufruft -> = operator für diese Klasse überschreiben-> Quasi eine Value klasse, die jeden beleibeigen wert zugewiesen bekommen kann
// der output iterator gibt einen pointer auf diese Klasse zurück und sobald ein assigment gemacht wird, wird einfach command aufgerufen
// dadurch ist aber das Konzept des command mappers quatsch
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