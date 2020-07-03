#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <string>
#include <vector>
#include "production-rule.hpp"
#include "turtle-graphic.hpp"
#include "l-system-2d.hpp"

class FileHandler {

public:

    // === constructor ==============================================
    FileHandler(const std::string& filename): file_successfully_parsed_(false), input_filename_(filename) {};

    // === file handling ============================================
    void parse_file();
    bool is_file_successfully_parsed();

    // === l system initalisiation ==================================
    //TODO: concepts/sifnae um schnittstelle umzusetzen
    //template<typename LSystem>
    bool configure_l_system(LSystem2D& l_system);

    bool configure_turtle_graphic(TurtleGraphic& turtle_graphic);

private:

    int width_;
    int height_;
    double short_line_length_;
    double line_length_;
    double turn_angle_;
    std::string export_filename_;

    bool file_successfully_parsed_;
    std::string input_filename_;

   

    std::string start_axiom_;
    std::vector<ProductionRule> production_rules;

};
#endif
