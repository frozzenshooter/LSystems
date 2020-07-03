#include "file-handler.hpp"


// === file handling ============================================
void FileHandler::parse_file() {
    // TODO: parsing

    start_axiom_ = "X";
    production_rules.emplace_back('X', "YF+XF+Y");
    production_rules.emplace_back('Y', "XF-YF-X");
    file_successfully_parsed_ = true;
};

bool FileHandler::is_file_successfully_parsed() {
    return file_successfully_parsed_;
};

// === l system initalisiation ==================================
/*
Configures the l system with the parsed data (can be used to configure multiple l systems with the same data)
*/
//template<typename LSystem>
bool FileHandler::configure_l_system(LSystem2D& l_system) {
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

/*
Configures the tutrle which will draw the l system (can be used to configure multiple turtles with the same data)
*/
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