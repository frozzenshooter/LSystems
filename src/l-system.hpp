#ifndef L_SYSTEM_HPP
#define L_SYSTEM_HPP

#include "production.hpp"
#include <unordered_map>
#include <string>

/*
This class represents a L-system, consisting of the grammar(productions and axiom).

There are some formal restrictions for the templates, because otherwise it won't be useable as intended.
Because of the self-similarity of a L-system, the axiom and the successor of the production should have the same type.
This type consitst of smaller objects, which can be represented by the Predecessor. These objects have to offer a function to compare them to enable the rewriting.

In conclusion a successor object consits of Predecessor objects. The rewriting will replace the Predecessor object with a Successor object and therefore with some Predecessor objects.

An example for this is char as Predeccesor and String as Successor. A char can be compared with another char.
If such a char is replaced in a string with the Successor string, the result will be a string, consisting of chars.
*/
template <typename Predecessor, typename Successor>
class LSystem {
public:
    void set_axiom(const Successor& axiom) {
        axiom_ = axiom;
    }

    // tremplate is needed because of compile error: https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2143?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(C2143)%26rd%3Dtrue&view=vs-2019
    std::template shared_ptr<Successor> get_axiom() {
        return std::make_shared<Successor>(axiom_);
    }

    void add_production(const Production<Predecessor, Successor>& production) {
        auto it = production_rules_.find(production.get_predecessor());

        if (it == production_rules_.end()) {
            production_rules_.insert(std::make_pair(production.get_predecessor(), production));
        }
        else {
            //TODO andere Exception nicht nur die Standard exception
            throw new std::exception("Rule for the same non terminal already existing");
        }
    }

    std::template shared_ptr<Successor> get_successor(const Predecessor& predecessor) {
        //Verbessern, da das erzeugen eines shared pointers bl�d ist -> evt nur pointer speichern??
        // bzw ist es effizient eine referenz zu bekommen und das dann mit make shared aufzurufen ? wird daf�r dann das objekt genutzt bzw was passiert kann zur Laufzeit passieren

        auto it = production_rules_.find(predecessor);

        if (it != production_rules_.end()) {
            return std::make_shared<Successor>(it->second.get_successor());
        }

        return nullptr;
    }

private:
    Successor axiom_;
    std::unordered_map<Predecessor, Production<Predecessor, Successor>> production_rules_;
};

#endif