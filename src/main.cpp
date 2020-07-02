#include <iostream>

#include "LSystem2D.hpp"
#include "TestTurtle.hpp"
#include "Parser.hpp"


int main() {

    LSystem2D test{ "F" };
    test.add_Production_Rule('F', "F+F--F+F");

    auto result = test.get_result(3);

    std::cout << result << std::endl;

    TestTurtle a{};

    Parser p{a};

    p.parse_and_draw(result);

    return 0;
}