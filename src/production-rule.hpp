#ifndef PRODUCTION_RULE_HPP
#define PRODUCTION_RULE_HPP

#include <string>


/*
This class represents a production rule of a LSystem.

A production rule consists of a non_terminal and an replacement.

The non_terminal in an LSystem will be replaced with the replacement.

TODO: Bennenung nich sauber - handelt es sich wirklich um eine nonterminal und eine rule ? weil eigentlich ist das gesamte eine production rule und die rule ist eig ein axiom oder so

zb: start_axiom: start_object
    non_terminal: predecessor 
    rule: successor
*/
template<typename Nonterminal, typename Replacment>
class ProductionRule {
public:
    // === constructor ==============================================
    ProductionRule(const Nonterminal& non_terminal, const Replacment& production_rule) 
        : non_terminal_(non_terminal), production_rule_(production_rule) 
    {
    }

    const Nonterminal& get_non_terminal() const {
        return non_terminal_;
    }

    const Replacment& get_production_rule() const {
        return production_rule_;
    }

private:
    Nonterminal non_terminal_;
    Replacment production_rule_;
};

#endif