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
        Node(std::list<std::weak_ptr<std::string>>& strings, const std::string& relevant_data)
        {
             //TODO find if there is a string similar to relevant_data

             // if so save the shared pointer in the list
                
             auto exists_string = false;
             if (exists_string) {

                 // save the shared pointer so the data will not be deleted
                 relevant_string_ = std::make_shared<std::string>(new std::string(relevant_data));

             } else {

                 // new string needs to be added and shared_ptr needs to be stored in node and in list
                 
                 auto pointer = std::make_shared<std::string>(new std::string(relevant_data));
                 relevant_string_ = pointer;
                 strings.emplace_back(pointer);
             }
        };

        void replace() {
            // falls selber keine Daten vorhanden sind - kindknoten dursuchen wer verantwortlich ist
            // immer wenn ein knoten übrig ist kann ein Knoten in der Liste angepasst werden bzw ein neuer hinzugefügt werden - man weiß nicht unbedingt, wie viele leute auf den String verweisen
            // evt doch mit shared_pointer lösen
            // vlt mit iterator einfacher als mit index -> man muss sich nicht direkt merken welche Node für welchen Index verantwortlich ist
        };

    private:

        std::shared_ptr<std::string> relevant_string_;
        std::weak_ptr<Node> parent_;
        std::vector<Node> children_;
    };

public:

    LSystem() {

    }

    ~LSystem() {

    }

    void clear() {
        strings_.clear();
        start_node_.reset(new Node(strings_, ""));
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
    std::unique_ptr<Node> start_node_;
    std::list<std::weak_ptr<std::string>> strings_;
};

#endif