#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include "turtle-graphic.hpp"

class Parser {

    //TODO rename to l system 2d parser or sth like this - can only parse one special grammar

private:
    // === char validation functions ================================
    bool is_terminal(char ch);

    bool is_whitespace(char ch);

    bool ignore_char(char ch);

    // === function call handling ===================================
    void handle(char ch);

public:

    // === constructor ==============================================
    Parser(TurtleGraphic& turtle_graphic) : turtle_graphic_(turtle_graphic) {};
    
    // === parsing/drawing ==========================================
    /*
    Parses the string and draws the interpretation with the turtlegraphic
    */
    template<typename LSystem>
    void parse_and_save_to_png(LSystem& l_system) {

        auto l_system_result = l_system.calculate();

        std::size_t current_index = 0;

        std::cout << "[Parsing started]" << std::endl;

        turtle_graphic_.init();

        while (current_index < l_system_result.size()) {

            auto ch = l_system_result[current_index];

            if (!ignore_char(ch)) {

                // call turtle only for valid chars
                handle(ch);
            }

            ++current_index;
        }

        std::cout << "[Parsing ended]: result will be exported as png" << std::endl;

        turtle_graphic_.save_to_png();
    }

private:
    TurtleGraphic& turtle_graphic_;    
};

#endif