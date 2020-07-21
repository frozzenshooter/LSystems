#ifndef L_SYSTEM_HANDLER_HPP
#define L_SYSTEM_HANDLER_HPP

#include <map>
#include <string>
#include <memory>
#include "production-rule.hpp"

template<typename LSystem>
class LSystemHandler {
public:

    LSystemHandler(std::shared_ptr<LSystem> l_system) : current_generation_(0), l_system_(l_system) {};

    /*
    Calculates the next generation of the l system
    */
    void calculate_next_gen() {
        for (auto i = (*l_system_).end(); i != (*l_system_).begin(); --i) {
            auto replacement = production_rules_[(*i)];

            if (!replacement.empty()) {
                (*l_system_).replace(i, i, replacement);
                //i += replacement.length()-1;
            }
            else {
                // TODO: what happens for terminals ? nothing ?
            }
        }

        ++current_generation_;
    };

    /*
    Calculatea the next generations of the current l system
    */
    void calculate_generation(int generation) {
        if (!start_axiom_.empty()
            && production_rules_.size() > 0)
        {
            for (int i = 0; i < generation; ++i) {
                calculate_next_gen();
            }
        }
        else {
            std::cout << "No start_axiom oder production rule was set" << std::endl;
        }
    };

    /*
    Sets the start axiom of the l system - if the l system has already generated generations, will these values be deleted
    */
    void set_start_axiom(const std::string& start_axiom) {
        if (current_generation_ > 0) {
            reset_l_system();
        }

        start_axiom_ = start_axiom;
    };

    void add_production_rule(ProductionRule rule) {
        production_rules_.insert(std::pair(rule.get_non_terminal(), rule.get_production_rule()));
    };

    void reset_l_system() {
        current_generation_ = 0;

        // TODO: IMPLEMENT IN L SYSTEM
        (*l_system_).clear();
    };

private:
    int current_generation_;
    std::shared_ptr<LSystem> l_system_;
    std::string start_axiom_;
    std::map<char, std::string> production_rules_;
};

#endif