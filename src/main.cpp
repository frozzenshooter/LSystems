#include <iostream>

#include "cairo-turtle.hpp"
#include "test-turtle.hpp"
#include "parser.hpp"
#include "file-handler.hpp"
#include <cairo.h>
#include "l-system-handler.hpp"
#include "l-system.hpp"
#include <string>
#include <sstream>
#include <map>

#include <iostream>

#include <fstream>

/*
TODO: make to enum class so no unneeded conversions done
*/
enum ConvertType {
    CTYPE_DOUBLE,
    CTYPE_INT,
    CTYPE_STRING,
    CTYPE_TWO_STRINGS
};

static std::map<std::string, ConvertType> HEADER_TYPES = {
    {"generations", CTYPE_INT},
    {"width", CTYPE_INT},
    {"height", CTYPE_INT},
    {"line_width", CTYPE_DOUBLE},
    {"line_length", CTYPE_DOUBLE},
    {"short_line_length", CTYPE_DOUBLE},
    {"turn_angle", CTYPE_DOUBLE},
    {"export_filename", CTYPE_STRING},
    {"axiom", CTYPE_STRING},
    {"rule", CTYPE_TWO_STRINGS}
};


ConvertType get_convert_type(const std::string& header) {

   auto it = HEADER_TYPES.find(header);

   if (it != HEADER_TYPES.end()) {

       return it->second;
   }
   else {
       auto str = "No specification for the header: '" + header + "' found.";
       throw new std::exception(str.c_str());
   }

}

template <typename T>
T convert(std::stringstream& ss) {

    T value;

    ss >> value;

    ret value;
}

void analyse_header(std::string header, std::stringstream& ss) {

    auto type = get_convert_type(header);

    switch (type)
    {
    case CTYPE_DOUBLE:
        double f = convert<double>(ss);
        break;
    case CTYPE_INT:
        break;
    case CTYPE_STRING:
        break;
    case CTYPE_TWO_STRINGS:
        break;
    default:
        break;
    }

}


int main() {



   

















    /*

    Concept:

        FileHandler loads data from file

        LSystemHandler manages the data of the l_system datastructure
        LSystemHandler uses a template to specifiy the datastructure - later on a semantic interface (concepts c++ 20)
        LSystemHandler needs this functions from the datastructure: TODO

        Parser gets the l_system data as input, inspects and calls the appropriate function of the turtle (on the fly)

        Turtle: Interface which enbales the export of the parsed data specified by the implementation of the turtle

    */

    //TODO: when do you need a copy/assignment constructor operator ? => have the std:: ... objects(stack,..) issues which need to explizit define them?

    //TODO: exception handling

    //TODO: style des codes -> tabs /spaces beachtet ?

    // alignments der einzelnen klassen in Ordnung ?

    //TODO getter and setter inline if to do sth - if not the compiler will link them away

    FileHandler handler;

    std::ifstream input_stream{ "test_file_space.ls" };

    handler.load_configuration(input_stream);

    handler.parse_file("test_file.ls");


    LSystem l_system;

    l_system.set_start_axiom(handler.start_axiom_);

    for (auto rule : handler.production_rules_) {
        l_system.add_production_rule(rule);
    }

    TestTurtle t;
    Parser p{ t };

    LSystemHandler<LSystem, Parser> lsystem_handler(l_system);

    lsystem_handler.calculate_generation(5, p);


    /*
    CairoTurtle t;
    t.configure(config);

    TestTurtle t;

    Parser p{t};
    p.parse_and_save_to_png(test);

    */

    return 0;
}