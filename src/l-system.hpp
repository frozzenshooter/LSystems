#ifndef L_SYSTEM_HPP
#define L_SYSTEM_HPP

#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <memory>
#include "production-rule.hpp"


class LSystem {

private:
    class Node {
    public:
        Node(std::list<std::string>& strings, const std::string& relevant_data)
        {
             auto it = std::find(strings.begin(), strings.end(), relevant_data);

             if (it != strings.end()) {

                 // save the iterator
                 relevant_string_it_ = it;

             } else {

                 // new string needs to be added and iterator hold
                 strings.emplace_back(relevant_data);
                 relevant_string_it_ = std::find(strings.begin(), strings.end(), relevant_data);
             }
             
        };

        void replace() {

        };

    private:

        std::list<std::string>::iterator relevant_string_it_;
        std::vector<std::shared_ptr<Node>> children_;



    };

public:

    LSystem() {

    }

    ~LSystem() {

    }

    void replace(std::size_t index, const std::string& replacement) {

        // falls keine initale node und index = 0
        //  -> neue startnode erstellen

        // ansonsten die korrekte node durhc rekursiven aufruf suchen und die neuen unterknoten erstellen
        // update der relevanten indices 

    };


    void get_char(std::size_t index);
    std::size_t size();


private:
    std::shared_ptr<Node> start_node_;
    std::list<std::string> strings_;
};

#endif