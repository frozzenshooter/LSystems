#include "l-system-2d.hpp"
#include <iostream>

// === constructor ==================================================
LSystem2D::LSystem2D(const std::string& start_axiom) : start_axiom_(start_axiom), currentState_("") {}


// === production rules =============================================

/*
* Adds a production rule consiting of a nonTerminal which will be replaced with the production
*/
void LSystem2D::add_production_rule(const char non_terminal, const std::string& production) {
        
    // TODO: validate rule (is already the same rule there + do i override a rule)
    // remove empty whitespace
    production_rules_.insert(std::pair(non_terminal, production));
}

void LSystem2D::remove_production_rules() noexcept{
    production_rules_.clear();
}

// === l system calculations ========================================

/*
* Calculates the next generation of the l system
*/
void LSystem2D::CalculateNextGeneration() {

    //TODO PERFORMANT WAY - dont copy it ??
    std::string nextState;

    for (std::size_t i = 0; i < currentState_.size(); ++i) {

        auto key = currentState_[i];

        auto production = production_rules_[key];

        // TODO: better way to append string/char ?
        if (!production.empty()) {

            nextState.append(production);

        }
        else {
            nextState.push_back(key);
        }
    }

    std::cout << currentState_.size() << std::endl;

    currentState_ = nextState;
}

/*
* Calculates the resulting (generation) string of the given l system
*/
const std::string& LSystem2D::get_result(const std::size_t generation) {
       
    currentState_ = start_axiom_;

    if (production_rules_.size() > 0) {
        
        for (std::size_t i = 0; i < generation; ++i) {

            CalculateNextGeneration();
        }
    }

    return currentState_;
}
