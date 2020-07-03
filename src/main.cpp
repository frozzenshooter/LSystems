#include <iostream>

#include "l-system-2d.hpp"
#include "cairo-turtle.hpp"
#include "test-turtle.hpp"
#include "parser.hpp"
#include "file-handler.hpp"
#include <cairo.h>


int main() {

    //TODO: Performance improvements: dont copy the string in the l2 system -> only work with the reference

    //TODO: move to the startpoint in cairo tutrle to fix useless line at the end

    //TODO: exception handling

    //TODO: validation rules

    //TODO: style des codes -> tabs /spaces beachtet ?

    //PRODUCTION RULES PER COPY ÜBERGEBEN DAMIT MAN DIE REGELN FÜR MEHRERE VERWENDEN KANN

    // alignments der einzelnen klassen in Ordnung ?

    //TODO getter and setter inline if to do sth - if not the compiler will link them away

    // Sierpinski
    LSystem2D test;

    FileHandler handler{ "lsystem.ls" };

    // TODO: BETTER IDEA FOR FILE HANDLER - ONLY PARSES AND RETRUNS THE VALUES 
    // ANOTHER CLASS WILL CONFIGURE THE TURTLE GRAPHIC / L_SYSTEM

    handler.parse_file();

    CairoTurtle a;

    if (handler.configure_l_system(test) && handler.configure_turtle_graphic(a)) {

        auto result = test.get_result(14);

        Parser p{ a };

        p.parse_and_draw(result);

        a.save_to_png();
    }
   
    return 0;
}