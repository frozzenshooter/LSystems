#include <iostream>

#include "l-system-2d.hpp"
#include "cairo-turtle.hpp"
#include "test-turtle.hpp"
#include "parser.hpp"
#include "file-handler.hpp"
#include <cairo.h>


int main() {

    //TODO: Performance improvements: dont copy the string in the l2 system -> only work with the reference
    // other data object?

    //TODO: exception handling

    //TODO: validation rules

    //TODO: style des codes -> tabs /spaces beachtet ?

    //PRODUCTION RULES PER COPY ÜBERGEBEN DAMIT MAN DIE REGELN FÜR MEHRERE VERWENDEN KANN

    // alignments der einzelnen klassen in Ordnung ?

    //TODO getter and setter inline if to do sth - if not the compiler will link them away

    // Sierpinski
    //LSystem2D test;

    FileHandler handler;

    handler.parse_file("test_file.ls");

    // TODO: BETTER IDEA FOR FILE HANDLER - ONLY PARSES AND RETRUNS THE VALUES 
    // ANOTHER CLASS WILL CONFIGURE THE TURTLE GRAPHIC / L_SYSTEM

    /*handler.parse_file();

    CairoTurtle a;

    if (handler.configure_l_system(test) && handler.configure_turtle_graphic(a)) {

        auto result = test.get_result(14);

        Parser p{ a };

        p.parse_and_draw(result);

        a.save_to_png();
    }*/
   
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

bool configure_turtle_graphic(TurtleGraphic& turtle_graphic);

bool FileHandler::is_file_successfully_parsed() {
    return file_successfully_parsed_;
};

// === l system initalisiation ==================================


/*
Configures the tutrle which will draw the l system (can be used to configure multiple turtles with the same data)

bool FileHandler::configure_turtle_graphic(TurtleGraphic& turtle_graphic) {

    //TODO: not used for now - better handling of the configuration needed
    //turtle_graphic.set_export_filename();
    //turtle_graphic.set_line_width();
    //turtle_graphic.set_dimensions();
    turtle_graphic.set_line_length(3);
    turtle_graphic.set_short_line_length(3);
    turtle_graphic.set_turn_angle(60.0);

    return true;
}


    start_axiom_ = "X";
    production_rules.emplace_back('X', "YF+XF+Y");
    production_rules.emplace_back('Y', "XF-YF-X");
    file_successfully_parsed_ = true;
*/