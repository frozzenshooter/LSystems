#ifndef L_SYSTEM_GENERATION_HPP
#define L_SYSTEM_GENERATION_HPP

/*
    TODO
*/
//template<template <typename, typename> class LSystem, typename Predecessor, typename Successor, typename OutputIterator>
template< typename LSystem, typename Predecessor, typename Successor, typename OutputIterator>
void calculate_l_system_generation(LSystem& l_system, int generation, OutputIterator& output_iterator, std::shared_ptr<Successor> current_value = nullptr) {

    if (current_value == nullptr) {
        current_value = l_system.get_axiom();
    }

    // Successor needs an iterator !!! -> NEEDS TO BE IN THE INTERFACE DESCRIPTION

    for (auto part : *(current_value)) {

        if (generation > 0) {

            auto successor = l_system.get_successor(part);

            if (successor == nullptr) {
                //++output_iterator << part;
                output_iterator.handle(part);
            }
            else {
                calculate_l_system_generation<LSystem, Predecessor, Successor, OutputIterator>(l_system, generation - 1, output_iterator, successor);
            }
        }
        else {

            //++output_iterator << part;
            output_iterator.handle(part);
        }
    }
}
#endif