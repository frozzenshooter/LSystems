#ifndef L_SYSTEM_GENERATION_HPP
#define L_SYSTEM_GENERATION_HPP

#include <memory>

/*
This function calculates a generation of a L-system.

The L-system needs to provide certain functionality, to be able to fullfill the needs. The L-system has as templates the predeccessor and successor type, which have additional restrictions.
The restriction for the successor and predecessor are descriebed in the l-system.hpp file.

Additional to the restrictions for the types because of the L-system, there are restrictions because of the generation itself.
The successor type needs to enable the use in a for loop, iterating over objects of the predecessor type.

This function calculates a generation in a recursive manner and hands over the result to an output iterator. The output iterator has to provide the typical functionality of such an iterator.

It is possible to handover a previous result, as pointer to a successor object, and calculate from that generation ongoing. If no pointer is provided the axiom of the L-system is used.
*/
template<template <typename, typename> class LSystem, typename Predecessor, typename Successor, typename OutputIterator>
void calculate_l_system_generation(LSystem<Predecessor, Successor>& l_system, unsigned int generation, OutputIterator& output_iterator, std::shared_ptr<Successor> current_value = nullptr) {
    if (current_value == nullptr) {
        // inital value
        current_value = l_system.get_axiom();
        
        if (current_value == nullptr) {
            throw new std::runtime_error("L-system didn't return an axiom");
        }
    }

    for (auto&& part : *(current_value)) {
        if (generation > 0) {
            // rewrite needed - get production result
            auto successor = l_system.get_successor(part);

            if (successor == nullptr) {
                // no production found, it is therefore a terminal and can be handed over directly
                *output_iterator = part;
                ++output_iterator;
            }
            else {
                calculate_l_system_generation<LSystem, Predecessor, Successor, OutputIterator>(l_system, generation - 1, output_iterator, successor);
            }
        }
        else {
            // max depth of recursion reached
            *output_iterator = part;
            ++output_iterator;
        }
    }
}
#endif