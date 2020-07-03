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