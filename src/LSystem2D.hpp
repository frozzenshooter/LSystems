#ifndef LSYSTEM_2D_HPP
#define LSYSTEM_2D_HPP

#include <map>
#include <string>

class LSystem2D{

private:
    void CalculateNextGeneration();

public:
    LSystem2D(const std::string& start_axiom);

    void add_Production_Rule(const char non_terminal, const std::string& production);
    void remove_Production_Rules() noexcept;
    const std::string& get_result(const std::size_t generation);

private:
    std::map<char, std::string> production_rules_;
    std::string start_axiom_;
    std::string currentState_;

};

#endif 