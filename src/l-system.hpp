#ifndef L_SYSTEM_HPP
#define L_SYSTEM_HPP

#include <unordered_map>
#include <string>
#include <memory>

/*
This class represents a L-system, holding the grammar(productions and axiom).

There are some formal restrictions for the templates, because otherwise it won't be useable as intended.
Because of the self-similarity of a L-system, the axiom and the successor have the same type.

The succesor should be able to containt objects of itself for this too. Additonal, the successor type has to consist of smaller objects, the predecessors.
These objects have to offer a function to compare them to enable the rewriting.

An example for this is char as Predeccesor and String as Successor. A char can be compared with another char.
If such a char is replaced in a string(e.g. axiom) with a successor string, the result will be a string, consisting of chars.
*/
template <typename Predecessor, typename Successor>
class LSystem {
public:
    void set_axiom(Successor axiom) {
        axiom_ = std::make_shared<Successor>(std::move(axiom));
    }

    std::template shared_ptr<Successor> get_axiom() {
        // template is needed because of compiler error: https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2143?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(C2143)%26rd%3Dtrue&view=vs-2019

        return axiom_;
    }

    void add_production(Predecessor predecessor, Successor successor) {
        auto it = productions_.find(predecessor);

        if (it == productions_.end()) {
            auto suc_ptr = std::make_shared<Successor>(std::move(successor));

            productions_.insert(std::make_pair(predecessor, suc_ptr));
        }
        else {
            throw new std::logic_error("Production for the same predecessor already exists");
        }
    }

    std::template shared_ptr<Successor> get_successor(const Predecessor& predecessor) {
        auto it = productions_.find(predecessor);

        if (it != productions_.end()) {
            return it->second;
        }

        return nullptr;
    }

private:
    std::shared_ptr<Successor> axiom_;
    std::unordered_map<Predecessor, std::shared_ptr<Successor>> productions_;
};

#endif