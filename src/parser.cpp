#include "parser.hpp"

// === char validation functions ====================================
/*
Checks if the next char has to be skipped
*/
bool Parser::ignore_char(char ch) {
    return !is_whitespace(ch) && !is_terminal(ch);
}

/*
Checks if the char is a whitespace
*/
bool Parser::is_whitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '\f' || ch == '\v';
}

/*
Checks if the char is part of the l system grammar
*/
bool Parser::is_terminal(char ch) {
    return ch == 'F' || ch == 'f' || ch == '-' || ch == '+' || ch == '[' || ch == ']';
}

// === function call handling =======================================
/*
Handles the turtle function call for the char
*/
void Parser::handle(char ch) {
    switch (ch)
    {
    case 'F':
        turtle_.draw();
        break;
    case '-':
        turtle_.turn_left();
        break;
    case 'f':
        turtle_.move();
        break;
    case '+':
        turtle_.turn_right();
        break;
    default:
        // do nothing
        break;
    }
}