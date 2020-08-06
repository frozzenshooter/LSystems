#include <string>
#include "l-system.hpp"
#include "l-system-generation.hpp"
#include "command-mapping-iterator.hpp"
#include "test-turtle.hpp"
#include "cairo-turtle.hpp"

//TODO: exception handling


/*
Shows example fractal generations under the use of a L-system and a cairo turtle.
*/
int main() {

    // Sierpinksi
    LSystem<char, std::string> l_system_sierpinksi;
    l_system_sierpinksi.set_axiom("X");
    l_system_sierpinksi.add_production('X', "YF+XF+Y");
    l_system_sierpinksi.add_production('Y', "XF-YF-X");

    // setup turtle for sierpinksi triangle
    CairoTurtle cairo_turtle_sierpinksi;
    cairo_turtle_sierpinksi.set_turning_angle(60.0);
    cairo_turtle_sierpinksi.set_line_lenght(3);

    CommandMappingIterator mapit{ cairo_turtle_sierpinksi };

    // Calculate and save sierpinski
    calculate_l_system_generation<LSystem, char, std::string, CommandMappingIterator>(l_system_sierpinksi, 9, mapit);
    cairo_turtle_sierpinksi.save_to_png("sierpinski.png");


    // Hilbert
    LSystem<char, std::string> l_system_hilbert;
    l_system_hilbert.set_axiom("L");
    l_system_hilbert.add_production('L', "+RF-LFL-FR+");
    l_system_hilbert.add_production('R', "-LF+RFR+FL-");

    // setup turtle for hilbert curve
    CairoTurtle cairo_turtle_hilbert;
    cairo_turtle_hilbert.set_turning_angle(90);
    cairo_turtle_hilbert.set_line_lenght(5);

    // Mapping iterator
    CommandMappingIterator mapit_hilbert{ cairo_turtle_hilbert };

    // Calculate and save hilbert
    calculate_l_system_generation<LSystem, char, std::string, CommandMappingIterator>(l_system_hilbert, 7, mapit_hilbert);
    cairo_turtle_hilbert.save_to_png("hilbert.png");


    // Example with back inserter
    //std::vector<char> result_l_system;

    //auto backin = std::back_insert_iterator(result_l_system);

    //calculate_l_system_generation<LSystem<char, std::string>, char, std::string, std::back_insert_iterator<std::vector<char>>>(l_system_sierpinksi, 8, backin);

    //std::cout << "Vector size: " << result_l_system.size() << std::endl;

    return 0;
}