#ifndef LSYSTEM_2D_HPP
#define LSYSTEM_2D_HPP

#include <map>
#include <string>
#include "production-rule.hpp"

class LSystem2D{

private:
    // === l system calculations ========================================
    void CalculateNextGeneration();

public:

    // === constructor ==================================================
    LSystem2D::LSystem2D() : generations_(0), start_axiom_(""), currentState_("") {}

    // === configuration ============================================
    void configure();

    // === calculation ==============================================
    const std::string& calculate();

private:

    int generations_;
    std::string start_axiom_;
    std::string currentState_;
    std::map<char, std::string> production_rules_;
};

#endif 