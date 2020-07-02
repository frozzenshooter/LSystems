#ifndef LSYSTEM
#define LSYSTEM


#include <string>

class LSystem
{

public:

    virtual ~LSystem() {};

    // Production rule handling
    virtual void add_Production_Rule(const char nonTerminal, const std::string& production) = 0;
    virtual void remove_Production_Rules() = 0;

    virtual const std::string& get_result(const int generation) = 0;

};

#endif
