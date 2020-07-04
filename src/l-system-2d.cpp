#include "l-system-2d.hpp"
#include <iostream>

/*
Configures the l system
*/
void LSystem2D::configure(const Configuration& configuration) {

    generations_ = configuration.generations_;

    start_axiom_ = configuration.start_axiom_;

    // if l system was used bevor remove old data;
    production_rules_.clear();
    for (auto rule : configuration.production_rules_) {

        // TODO: validate rule (is already the same rule there + do i override a rule)
        // TODO: describe why this should be more efficient to just hold string now

        production_rules_.insert(std::pair(rule.get_non_terminal(), rule.get_production_rule()));
    }
};

/*
Calculate the result of the l system (for the defined generations) and return it
*/
const std::string& LSystem2D::calculate() {

    currentState_ = start_axiom_;

    if (production_rules_.size() > 0) {

        for (std::size_t i = 0; i < generations_; ++i) {

            CalculateNextGeneration();
        }
    }

    std::cout << "[Resulting size]: " << currentState_.size() << std::endl;
    
    return currentState_;
};

/*
Calculates the next generation of the l system
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

    currentState_ = nextState;
}
