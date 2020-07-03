#include <iostream>

#include "l-system-2d.hpp"
#include "cairo-turtle.hpp"
#include "test-turtle.hpp"
#include "parser.hpp"
#include <cairo.h>


int main() {

    //TODO: rename all files adn classes to small letters and underscores

    //TODO: Performance improvements: dont copy the string in the l2 system -> only work with the reference

    //TODO: move to the startpoint in cairo tutrle to fix useless line at the end

    //TODO: exception handling

    //TODO: validation rules

    //TODO: style des codes -> tabs /spaces beachtet ?

    // Sierpinski
    LSystem2D test{ "X" };
    test.add_Production_Rule('X', "YF+XF+Y");
    test.add_Production_Rule('Y', "XF-YF-X");

    auto result = test.get_result(14);

    CairoTurtle a{2000, 2000, "testfile.png"};
    a.set_turn_angle(60.0);
    a.set_line_length(3);

    Parser p{a};

    p.parse_and_draw(result);

    a.save_to_png();
    return 0;
}