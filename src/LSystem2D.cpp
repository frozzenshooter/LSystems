#include "LSystem2D.hpp"

void LSystem2D::CalculateNextGeneration() {

    std::string nextState;

    for (std::size_t i = 0; i < _currentState.size(); ++i) {

        auto key = _currentState[i];

        auto production = _production_rules[key];

        // TODO: better way to append string/char ?
        if (!production.empty()) {

            nextState.append(production);

        } else {
            nextState.push_back(key);
        }
    }

    _currentState = nextState;
}

LSystem2D::LSystem2D(const std::string& start_axiom): _start_axiom(start_axiom), _currentState("") {}

/*
* Adds a production rule consiting of a nonTerminal which will be replaced with the production
*/
void LSystem2D::add_Production_Rule(const char non_terminal, const std::string& production) {
        
    // TODO: validate rule (is already the same rule there + do i override a rule)
    // remove empty whitespace
    _production_rules.insert(std::pair(non_terminal, production));
}

void LSystem2D::remove_Production_Rules() noexcept{
    _production_rules.clear();
}

/*
* Calculates the resulting string of the given LSystem
* <generation> how often the rules should be applied to the current state to get the result
*/
const std::string& LSystem2D::get_result(const std::size_t generation) {
       
    _currentState = _start_axiom;

    if (_production_rules.size() > 0) {
        
        for (std::size_t i = 0; i < generation; ++i) {

            CalculateNextGeneration();
        }
    }

    return _currentState;
}
