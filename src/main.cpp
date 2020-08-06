#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "file-handler.hpp"
#include "l-system.hpp"
#include "l-system-generation.hpp"
#include "command-mapping-iterator.hpp"
#include "test-turtle.hpp"
#include "cairo-turtle.hpp"

//TODO: exception handling
int main() {
    FileHandler<char, std::string> handler;

    std::ifstream input_stream{ "test_file_space.ls" };

    handler.load_configuration(input_stream);

    handler.parse_file("test_file_3.ls");

    LSystem<char, std::string> l_system;

    l_system.set_axiom(handler.start_axiom_);

    for (auto rule : handler.production_rules_) {
        l_system.add_production(rule.get_predecessor(), *(rule.get_successor()));
    }

    CairoTurtle t;


    // EXAMPLE WITH BACK INSERTER
    // std::vector<char> result_l_system;

    //auto backin = std::back_insert_iterator(result_l_system);

    //calculate_l_system_generation<LSystem<char, std::string>, char, std::string, std::back_insert_iterator<std::vector<char>>>(l_system, 8, backin);

    //std::cout << "Vector size: " << result_l_system.size() << std::endl;

    //for (auto c : result_l_system) {
    //    p.handle(c);
    //}

    // CUSTOM OUTPUT ITERATOR
    t.set_turning_angle(90);
    t.set_line_lenght(5);

    CommandMappingIterator mapit{ t };
    calculate_l_system_generation<LSystem<char, std::string>, char, std::string, CommandMappingIterator>(l_system, 5, mapit);

    t.save_to_png("export_file1.png");

    t.reset();

    calculate_l_system_generation<LSystem<char, std::string>, char, std::string, CommandMappingIterator>(l_system, 9, mapit);

    t.save_to_png("export_file2.png");

    return 0;
}