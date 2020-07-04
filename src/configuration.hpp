#ifndef L_SYSTEM_CONFIGURATION_HPP
#define L_SYSTEM_CONFIGURATION_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "production-rule.hpp"

class Configuration {

public:

    // === turtle configuration data ================================
    int width_;
    int height_;
    int generations_;
    double short_line_length_;
    double line_length_;
    double turn_angle_;
    double line_width_;
    std::string export_filename_;

    // === l system configuration data ==============================
    std::string start_axiom_;
    std::vector<ProductionRule> production_rules_;

    void print() const{


        std::cout << "[Configuration]:" << std::endl;
        std::cout << "width: " << width_ << std::endl;
        std::cout << "height: " << height_ << std::endl;

        std::cout << "short_line_length: " << short_line_length_ << std::endl;
        std::cout << "line_length: " << line_length_ << std::endl;
        std::cout << "turn_angle: " << turn_angle_ << std::endl;
        std::cout << "line_width: " << line_width_ << std::endl;

        std::cout << "export_filename: " << export_filename_ << std::endl;

        std::cout << "generations: " << generations_ << std::endl;
        std::cout << "start_axiom: " << start_axiom_ << std::endl;

        for (auto rule : production_rules_) {
            std::cout << "rule: " << rule.get_non_terminal() << " => " << rule.get_production_rule() << std::endl;
        }
    }
};

#endif

