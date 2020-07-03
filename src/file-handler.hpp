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
    /*
    Configures the l system with the parsed data (can be used to configure multiple l systems with the same data)
    */
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
