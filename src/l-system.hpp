#ifndef L_SYSTEM_HPP
#define L_SYSTEM_HPP


#include <unordered_map>
#include <string>
#include <exception>
#include "production-rule.hpp"

class LSystem {
public:

    void set_start_axiom(const std::string& start_axiom) {
        start_axiom_ = start_axiom;
    }

    const std::string& get_start_axiom() const noexcept{
        return start_axiom_;
    }

    void add_production_rule(const ProductionRule& rule) {
   

        auto it = production_rules_.find(rule.get_non_terminal());

        if (it == production_rules_.end()) {
            production_rules_.insert(std::make_pair(rule.get_non_terminal(), rule));
        }
        else {
            throw new std::exception("Rule for the same non terminal already existing");
        }
    }

    const ProductionRule& get_production_rule(char non_terminal) {
   
        // MAP used for fast access because it will be called often
        // improvment to replace char with more flexible type
        auto it = production_rules_.find(non_terminal);

        if (it != production_rules_.end()) {

            return it->second;
        }
        else {
            //better way if there is a terminal -> https://stackoverflow.com/questions/58929539/how-to-return-null-as-reference-in-c
            //evt in production rule constructor mit bool -> is_valid/is_non_terminal -> quasi flag um dann später überprüfen zu können
            return ProductionRule('a', "abc");
        }

        // Alternative nicht de ganze Regel übergeben, sondern nur den String zum ersetzten -> die Funktion umbennenen in get_replacement
        // Wenn etwas nicht gefunden wurde einfach den char zurückgeben -> dort kann man dann auf gleichheit prüfen
    }

private:
    std::string start_axiom_;
    std::unordered_map<char, ProductionRule> production_rules_;
};

#endif