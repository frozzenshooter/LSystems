#ifndef L_SYSTEM_HPP
#define L_SYSTEM_HPP

#include <unordered_map>
#include <string>
#include <memory>

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
        axiom_ = std::make_shared<Successor>(axiom);
    }

    std::template shared_ptr<Successor> get_axiom() {
        // template is needed because of compiler error: https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2143?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(C2143)%26rd%3Dtrue&view=vs-2019
        
        return axiom_;
    }

    void add_production(const Predecessor& predeccessor, const Successor& successor) {
        auto it = productions_.find(predeccessor);

        //TODO ist es der beste weg das mit einem const ref into make shared zu machen ?
        if (it == productions_.end()) {
            auto suc_ptr = std::make_shared<Successor>(successor);

            productions_.insert(std::make_pair(predeccessor, suc_ptr));
        }
        else {
            //TODO andere Exception nicht nur die Standard exception
            throw new std::exception("Production for the same predecessor already exists");
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