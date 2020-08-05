#include <iostream>

#include "cairo-turtle.hpp"
#include "test-turtle.hpp"
#include "file-handler.hpp"
#include <cairo.h>
#include "l-system.hpp"
#include <string>
#include <sstream>
#include <map>

#include <iostream>
#include "l-system-generation.hpp"
#include <fstream>
#include "command-mapper.hpp"

/*

Concept:

    FileHandler loads data from file

    LSystemHandler manages the data of the l_system datastructure
    LSystemHandler uses a template to specifiy the datastructure - later on a semantic interface (concepts c++ 20)
    LSystemHandler needs this functions from the datastructure: TODO

    Parser gets the l_system data as input, inspects and calls the appropriate function of the turtle (on the fly)

    Turtle: Interface which enbales the export of the parsed data specified by the implementation of the turtle

*/

//TODO: when do you need a copy/assignment constructor operator ? => have the std:: ... objects(stack,..) issues which need to explizit define them?

//TODO: exception handling

//TODO: style des codes -> tabs /spaces beachtet ?


int main() {

    FileHandler<char, std::string> handler;

    std::ifstream input_stream{ "test_file_space.ls" };

    handler.load_configuration(input_stream);

    handler.parse_file("test_file.ls");


    LSystem<char, std::string> l_system;

    l_system.set_axiom(handler.start_axiom_);

    for (auto rule : handler.production_rules_) {

        Production p(rule.get_predecessor(), rule.get_successor());
        l_system.add_production(p);
    }

    CairoTurtle t;

    std::vector<char> result_l_system;

    // EXAMPLE WITH BACK INSERTER
    //auto backin = std::back_insert_iterator(result_l_system);

    //calculate_l_system_generation<LSystem<char, std::string>, char, std::string, std::back_insert_iterator<std::vector<char>>>(l_system, 8, backin);

    //std::cout << "Vector size: " << result_l_system.size() << std::endl;

    //for (auto c : result_l_system) {
    //    p.handle(c);
    //}


    // CUSTOM OUTPUT ITERATOR
    CommandMappingIterator mapit{t};
    calculate_l_system_generation<LSystem<char, std::string>, char, std::string, CommandMappingIterator>(l_system, 9, mapit);

    t.save_to_png("export_file2.png");

    return 0;
}