#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <memory>
#include "turtle-graphic.hpp"

class Parser {
    //TODO rename to l system 2d parser or sth like this - can only parse one special grammar

private:
    // === char validation functions ================================
    bool is_terminal(char ch);

    bool is_whitespace(char ch);

    bool ignore_char(char ch);

    // === function call handling ===================================
    
public:

    void handle(char ch);

    // === constructor ==============================================
    Parser(TurtleGraphic& turtle_graphic) : turtle_graphic_(turtle_graphic) {};

private:
    TurtleGraphic& turtle_graphic_;
};

#endif