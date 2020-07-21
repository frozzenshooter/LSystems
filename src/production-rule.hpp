#ifndef PRODUCTION_RULE_HPP
#define PRODUCTION_RULE_HPP

#include <string>

class ProductionRule {
public:
    // === consrtuctor ==============================================
    ProductionRule(char non_terminal, const std::string& production_rule) : non_terminal_(non_terminal), production_rule_(production_rule) {
        //TODO: Ist das so effizient mit dem übergeben der strings
    }

    char get_non_terminal() const {
        return non_terminal_;
    }

    const std::string& get_production_rule() const {
        return production_rule_;
    }

private:
    char non_terminal_;
    std::string production_rule_;
};

#endif