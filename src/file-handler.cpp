#include <iostream>
#include <fstream>
#include "file-handler.hpp"


// === file handling ============================================

/*
Parses a configuration file and returns a configuration for the turtle and l system
*/
void FileHandler::parse_file(const std::string& input_filename) {
    
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

                generation_count_ = std::stoi(line.substr(value_start, line.size() - 1));
            }
            else if (header.compare("width") == 0) {

                width_ = stoi(line.substr(value_start, size));
            }
            else if (header.compare("height") == 0) {

                height_ = stoi(line.substr(value_start, size));
            }
            else if (header.compare("line_width") == 0) {

                line_width_ = stod(line.substr(value_start, size));
            }
            else if (header.compare("line_length") == 0) {

                line_length_ = stod(line.substr(value_start, size));
            }
            else if (header.compare("short_line_length") == 0) {

                short_line_length_ = stod(line.substr(value_start, size));
            }
            else if (header.compare("turn_angle") == 0) {

                turn_angle_ = stod(line.substr(value_start, size));
            }
            else if (header.compare("export_filename") == 0) {

                export_filename_ = line.substr(value_start, size);
            }
            else if (header.compare("axiom") == 0) {

                start_axiom_ = line.substr(value_start, size);
            }
            else if (header.compare("rule") == 0) {

                // split rule in non_terminal and production_rule
                auto rule = line.substr(value_start, size);

                production_rules_.emplace_back(rule[0], rule.substr(3));
            }
            else {
                std::cout << "[Unknown header]: " << header << std::endl;
            }

         }

        // print resulting
        print();

    } else {
        std::cout << "Not able to read file - default configuration will be used" << std::endl;
    }
};

/*
Prints the loaded data
*/
void FileHandler::print() const {

    std::cout << "[Configuration loaded from file]:" << std::endl;
    std::cout << "width: " << width_ << std::endl;
    std::cout << "height: " << height_ << std::endl;

    std::cout << "short_line_length: " << short_line_length_ << std::endl;
    std::cout << "line_length: " << line_length_ << std::endl;
    std::cout << "turn_angle: " << turn_angle_ << std::endl;
    std::cout << "line_width: " << line_width_ << std::endl;

    std::cout << "export_filename: " << export_filename_ << std::endl;

    std::cout << "generation count: " << generation_count_ << std::endl;
    std::cout << "start_axiom: " << start_axiom_ << std::endl;

    for (auto rule : production_rules_) {
        std::cout << "rule: " << rule.get_non_terminal() << " => " << rule.get_production_rule() << std::endl;
    }
}