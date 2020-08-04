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