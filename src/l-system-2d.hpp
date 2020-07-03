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
    LSystem2D::LSystem2D() : start_axiom_(""), currentState_("") {}

    // === axiom ========================================================
    void set_start_axiom(const std::string& start_axiom);

    // === production rules =============================================
    void add_production_rule(const ProductionRule& production_rule);
    void remove_production_rules() noexcept;

    const std::string& get_result(const std::size_t generation);

private:

    std::string start_axiom_;
    std::string currentState_;
    std::map<char, std::string> production_rules_;
};

#endif 