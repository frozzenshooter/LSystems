#include <iostream>

#include "LSystem2D.hpp"


int main() {

    LSystem2D testLSystem{"b"};

    testLSystem.add_Production_Rule('a', "ab");
    testLSystem.add_Production_Rule('b', "a");

    for (int i = 0; i < 20; ++i) {
        std::cout << testLSystem.get_result(i) << std::endl;
    }
    std::cin.get();
    return 0;
}