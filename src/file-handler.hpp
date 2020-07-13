#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <string>
#include <vector>
#include "production-rule.hpp"

class FileHandler {

public:

    /*
    Sets the default values for the data
    */
    FileHandler():
        width_(2000),
        height_(2000),
        generation_count_(0),
        short_line_length_(1.5),
        line_length_(3.0),
        turn_angle_(60.0),
        line_width_(1.0),
        export_filename_("export_file.png")    
    {

    }

    // === file handling ============================================
    void parse_file(const std::string& input_filename);
    void print() const;

    // === loaded data ==============================================
    int width_;
    int height_;
    int generation_count_;
    double short_line_length_;
    double line_length_;
    double turn_angle_;
    double line_width_;
    std::string export_filename_;

    std::string start_axiom_;
    std::vector<ProductionRule> production_rules_;
};
#endif
