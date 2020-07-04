#include <iostream>

#include "l-system-2d.hpp"
#include "cairo-turtle.hpp"
#include "test-turtle.hpp"
#include "parser.hpp"
#include "file-handler.hpp"
#include <cairo.h>


int main() {


    //TODO: when do you need a copy/assignment constructor operator ? => have the std:: ... objects(stack,..) issues which need to explizit define them?

    //TODO: Performance improvements: dont copy the string in the l2 system -> only work with the reference
    // other data object?

    //TODO: exception handling

    //TODO: validation rules

    //TODO: style des codes -> tabs /spaces beachtet ?

    // alignments der einzelnen klassen in Ordnung ?

    //TODO getter and setter inline if to do sth - if not the compiler will link them away

    FileHandler handler;

    LSystem2D lsystem;

    auto config = handler.parse_file("test_file.ls");

    lsystem.configure(config);

    CairoTurtle t;
    t.configure(config);

    Parser p{t};
    p.parse_and_save_to_png(lsystem);
   
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