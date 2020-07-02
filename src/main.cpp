#include <iostream>

#include "LSystem2D.hpp"


int main() {

    LSystem2D testLSystem{ "b" };

    testLSystem.add_Production_Rule('a', "ab");
    testLSystem.add_Production_Rule('b', "a");

    for (int i = 0; i < 10; ++i) {
        std::cout << testLSystem.get_result(i) << std::endl;
    }

    LSystem2D test2{ "F" };
    test2.add_Production_Rule('F', "F+F--F+F");

    for (int i = 0; i < 3; ++i) {
        std::cout << test2.get_result(i) << std::endl;
    }



    std::cin.get();
    return 0;
}