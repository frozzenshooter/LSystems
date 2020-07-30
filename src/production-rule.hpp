#ifndef PRODUCTION_RULE_HPP
#define PRODUCTION_RULE_HPP

#include <string>

template<typename Nonterminal, typename Rule>
class ProductionRule {
public:
    // === consrtuctor ==============================================
    ProductionRule(const Nonterminal& non_terminal, const Rule& production_rule) : non_terminal_(non_terminal), production_rule_(production_rule) {
        //TODO: Ist das so effizient mit dem übergeben der strings
    }

    const Nonterminal& get_non_terminal() const {
        return non_terminal_;
    }

    const Rule& get_production_rule() const {
        return production_rule_;
    }

private:
    Nonterminal non_terminal_;
    Rule production_rule_;
};

#endif