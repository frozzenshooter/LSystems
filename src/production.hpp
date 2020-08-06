#ifndef PRODUCTION_HPP
#define PRODUCTION_HPP

#include <memory>

/*
This class represents a production of the grammar of a L-system.
A production will be used in the rewritng process of a L-system.

--- Requirements for the templates, when used with a L-system ---

The Successor-Template has to fullfill some formal requirements. The successor has to be build from a combination of L-system alphabet objects.
These objects need be be comparable with the Prdeccessor-Template, so a correct replacement can be done. Thererfore the Predeccessor needs to offer a function
to compare itself with a object of the L-system alphabet.

For example the Predeccessor is a char and the Successor is a string.
A string is a combination of chars and while rewriting each char of a successor can be compared with a Predeccessor, another char.

*/
template<typename Predecessor, typename Successor>
class Production {
public:
    Production(const Predecessor& predecessor, const Successor& successor) : predecessor_(predecessor), successor_(std::make_shared<Successor>(successor)) {
    }

    const Predecessor& get_predecessor() const {
        return predecessor_;
    }

    std::shared_ptr<Successor> get_successor() const {
        return successor_;
    }

private:
    Predecessor predecessor_;
    std::shared_ptr<Successor> successor_;
};
#endif