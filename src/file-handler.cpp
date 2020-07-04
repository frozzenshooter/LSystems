#include <iostream>
#include <fstream>
#include "file-handler.hpp"


// === file handling ============================================

/*
Parses a configuration file and returns a configuration for the turtle and l system
*/
Configuration FileHandler::parse_file(const std::string& input_filename) {
    
    Configuration configuration;

    std::ifstream input_stream{ input_filename };

    std::cout << "[Reading Configuration file]: " << input_filename << std::endl;

    if (input_stream) {
        
        std::string line;
        while (std::getline(input_stream, line)) {

            auto header_end = line.find(':'); // if no : is used the whole line will be parsed as unknown header

            auto header = line.substr(0, header_end);
            std::size_t size = line.size() - 1;
            std::size_t value_start = header_end + 2; // after the : needs to be a space which will be ignored


            //TODO: EXCEPTION HANDLING FOR THE PARSING OF THE VALUES

            // switch not supported for strings -> if statements
            if (header.compare("generations") == 0) {

                configuration.generations_ = std::stoi(line.substr(value_start, line.size() - 1));
            }
            else if (header.compare("width") == 0) {

                configuration.width_ = stoi(line.substr(value_start, size));
            }
            else if (header.compare("height") == 0) {

                configuration.height_ = stoi(line.substr(value_start, size));
            }
            else if (header.compare("line_width") == 0) {

                configuration.line_width_ = stod(line.substr(value_start, size));
            }
            else if (header.compare("line_length") == 0) {

                configuration.line_length_ = stod(line.substr(value_start, size));
            }
            else if (header.compare("short_line_length") == 0) {

                configuration.short_line_length_ = stod(line.substr(value_start, size));
            }
            else if (header.compare("turn_angle") == 0) {

                configuration.turn_angle_ = stod(line.substr(value_start, size));
            }
            else if (header.compare("export_filename") == 0) {

                configuration.export_filename_ = line.substr(value_start, size);
            }
            else if (header.compare("axiom") == 0) {

                configuration.start_axiom_ = line.substr(value_start, size);
            }
            else if (header.compare("rule") == 0) {

                // split rule in non_terminal and production_rule
                auto rule = line.substr(value_start, size);

                configuration.production_rules_.emplace_back(rule[0], rule.substr(3));
            }
            else {
                std::cout << "[Unknown header]: " << header << std::endl;
            }

            }

        // print resulting
        configuration.print();

    } else {
        std::cout << "Not able to read file - default configuration will be used" << std::endl;
    }

    // return rvalue so it can be move assigned
    return configuration;
};
