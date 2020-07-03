#ifndef LSYSTEM_2D_HPP
#define LSYSTEM_2D_HPP

#include <map>
#include <string>

class LSystem2D{

private:
    // === l system calculations ========================================
    void CalculateNextGeneration();

public:
    // === constructor ==================================================
    LSystem2D(const std::string& start_axiom);

    // === production rules =============================================
    void add_production_rule(const char non_terminal, const std::string& production);
    void remove_production_rules() noexcept;

    const std::string& get_result(const std::size_t generation);

private:

    std::string start_axiom_;
    std::string currentState_;
    std::map<char, std::string> production_rules_;


};

#endif 