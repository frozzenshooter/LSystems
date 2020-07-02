#ifndef LSYSTEM_2D_HPP
#define LSYSTEM_2D_HPP

#include "LSystem.hpp"
#include <map>
#include <string>
#include <cassert>

class LSystem2D : public LSystem {

private:

    void CalculateNextGeneration() {

        std::string nextState;

        for (int i = 0; i < currentState.size(); ++i) {

            auto key = currentState[i];

            auto production = production_rules[key];

            // TODO: better way to append string/char ?
            if (!production.empty()) {

                nextState.append(production);

            } else {
                nextState.push_back(key);
            }
        }

        currentState = nextState;
    }


public:
    
    LSystem2D(const std::string& startaxiom): startAxiom(startaxiom), currentState("") {}

    void add_Production_Rule(const char nonTerminal, const std::string& production) {
        
        // TODO: validate rule (is already the same rule there + do i override a rule)
        production_rules.insert(std::pair(nonTerminal, production));
    }

    void remove_Production_Rules() noexcept{
        production_rules.clear();
    }

    const std::string& get_result(const int generation) {
       
        currentState = startAxiom;

        if (production_rules.size() > 0) {
        
            for (int i = 0; i < generation; ++i) {

                CalculateNextGeneration();
            }
        }

        return currentState;
    }

private:

    std::map<char, std::string> production_rules;
    std::string startAxiom;
    std::string currentState;
};

#endif 
