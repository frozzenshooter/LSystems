#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include "TurtleGraphic.hpp"

class Parser {

private:
    bool is_terminal(char ch);

    bool is_whitespace(char ch);

    bool ignore_char(char ch);

    void handle(char ch);

public:
    Parser(TurtleGraphic& turtle_graphic) : _turtle_graphic(turtle_graphic) {};

    void parse_and_draw(const std::string& l_system_result);

private:
    TurtleGraphic& _turtle_graphic;    
};

#endif