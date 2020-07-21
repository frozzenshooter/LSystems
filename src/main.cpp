#include <iostream>

#include "cairo-turtle.hpp"
#include "test-turtle.hpp"
#include "parser.hpp"
#include "file-handler.hpp"
#include <cairo.h>
#include "l-system-handler.hpp"
#include "l-system.hpp"
#include <string>
#include <sstream>

#include <iostream>

#include <fstream>

int main() {
    /*

    Concept:

        FileHandler loads data from file

        LSystemHandler manages the data of the l_system datastructure
        LSystemHandler uses a template to specifiy the datastructure - later on a semantic interface (concepts c++ 20)
        LSystemHandler needs this functions from the datastructure:
            - get_char(std::size_t index)
            - replace(std::size_t index, const std::string& replacement)
            - clear()
            -

        Parser gets the l_system data as input, inspects and calls the appropriate function of the turtle (on the fly)

        Turtle: Interface which enbales the export of the parsed data specified by the implementation of the turtle

    */

    //TODO: when do you need a copy/assignment constructor operator ? => have the std:: ... objects(stack,..) issues which need to explizit define them?

    //TODO: Performance improvements: dont copy the string in the l2 system -> only work with the reference
    // other data object?

    //TODO: exception handling

    //TODO: style des codes -> tabs /spaces beachtet ?

    // alignments der einzelnen klassen in Ordnung ?

    //TODO getter and setter inline if to do sth - if not the compiler will link them away

    FileHandler handler;

    //std::ifstream input_stream{ "test_file_space.ls" };

    //handler.load_configuration(input_stream);

    handler.parse_file("test_file.ls");


    LSystem l_system;

    l_system.set_start_axiom(handler.start_axiom_);

    for (auto rule : handler.production_rules_) {
        l_system.add_production_rule(rule);
    }

    TestTurtle t;
    Parser p{ t };

    LSystemHandler<LSystem, Parser> lsystem_handler(l_system);

    lsystem_handler.calculate_generation(5, p);


    /*
    CairoTurtle t;
    t.configure(config);

    TestTurtle t;

    Parser p{t};
    p.parse_and_save_to_png(test);

    */

    return 0;
}

/*
// === l system initalisiation ==================================
//TODO: concepts/sifnae um schnittstelle umzusetzen
/*
Configures the l system with the parsed data (can be used to configure multiple l systems with the same data)

template<typename LSystem>
bool configure_l_system(LSystem& l_system) {
    //TODO: concepts/sifnae um schnittstelle umzusetzen

    if (file_successfully_parsed_) {
        l_system.set_start_axiom(start_axiom_);

        //TODO: is this efficient ? because of reference problems later on ?
        for (auto& production_rule : production_rules) {
            l_system.add_production_rule(production_rule);
        }

        return true;
    }
    return false;
};
*/