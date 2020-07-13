#ifndef L_SYSTEM_HPP
#define L_SYSTEM_HPP

#include <map>
#include <vector>
#include <string>
#include <memory>
#include "production-rule.hpp"


class LSystem {

    class Node {
    public:
        Node(const std::string& start_axiom) {

        }

        std::size_t responsible_index_start_;
        std::size_t responsible_index_end_;
        std::vector<std::shared_ptr<Node>> children_;
    };

public:

    void replace(std::size_t index, const std::string& replacement);
    void get_char(std::size_t index);
    std::size_t size();


private:
    std::shared_ptr<Node> start_node_;
    std::vector<std::shared_ptr<std::string>> strings_;
};

#endif