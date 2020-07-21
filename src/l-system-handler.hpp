#ifndef L_SYSTEM_HANDLER_HPP
#define L_SYSTEM_HANDLER_HPP

#include <map>
#include <string>
#include <memory>
#include "production-rule.hpp"

template<typename LSystem, typename OutputIterator>
class LSystemHandler {
public:

    LSystemHandler(const LSystem& l_system) : l_system_(l_system) {};

    void calculate_generation(int generation, OutputIterator& output_iterator) {

        std::string start_axiom = l_system_.get_start_axiom(); // TODO später durch auto ersetzten

        calls_ = 0;

        //TODO: überprüfen ob leer
        calculate_recursive(generation, start_axiom, output_iterator);

        std::cout << "[Calls]: " << calls_ << std::endl;

    }

private:

    void calculate_recursive(int generation, std::string start_value, OutputIterator& output_iterator) {

        if (generation > 0) {

            for (char& c : start_value) {

                try {
                    auto rule = l_system_.get_production_rule(c);
                    if (rule.get_production_rule().compare("abc") != 0) {
                        calculate_recursive(generation - 1, rule.get_production_rule(), output_iterator);
                    }
                    else {
                        calls_++;
                        output_iterator.handle(c);
                    }
                   

                }
                catch (std::exception exception) {
                    // Must be a terminal symbol, which must be processed by the output iterator -> TODO: solve later not with an exception
                    // output_iterator << c;
                    // output_iterator++;
                    calls_++;
                    output_iterator.handle(c);
                   
                }
            }
        }
        else {
            for (char& c : start_value) {

                // calls the Turtle function
                // output_iterator << c;
                // output_iterator++;

                calls_++;
                output_iterator.handle(c);
            }
        }     
    }

private:
    size_t calls_;
    LSystem& l_system_;
};

#endif