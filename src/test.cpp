#include <string>
#include <iomanip>
#include "l-system.hpp"
#include "l-system-generation.hpp"
#include "command-mapping-iterator.hpp"
#include "test-turtle.hpp"
#include "cairo-turtle.hpp"

template<typename T>
void test(unsigned int test_id, std::string description, T&& operation) {
    std::cout << "Test-case " << test_id << ": " << std::setw(70) << std::left << std::move(description) << " ";
    try {
        operation();
        std::cout << "ok" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "unknown exception" << std::endl;
    }
}

// Turtle implementation to simplify the tests
class SaveTurtle : public Turtle {

public:
    ~SaveTurtle() override{}

    void move() override {
        commands.emplace_back('f');
    }

    void draw() override {
        commands.emplace_back('F');
    }

    void turn_right() override {
        commands.emplace_back('+');
    }

    void turn_left() override {
        commands.emplace_back('-');
    }

    std::vector<char> commands;
};



/*
Testcases (only for C0 coverage)
*/
int main() {

    unsigned int test_id = 0;

    // LSYSTEM TEST CASES

    test(++test_id, "L-system init (axiom with multiple productions)", []() {

        std::string axiom = "AB";
        char predecessorA = 'A';
        std::string successorAA = "AA";

        char predecessorB = 'B';
        std::string successorBB = "BB";


        LSystem<char, std::string> test_l_system;
    });

    test(++test_id, "L-system data init (two production for the same predecessor)", []() {

        std::string axiom = "AB";
        char predecessorA = 'A';
        std::string successorAA = "AA";


        LSystem<char, std::string> test_l_system;
        test_l_system.set_axiom(axiom);
        test_l_system.add_production(predecessorA, successorAA);

        bool exceptionThrown = false;
        try {
            test_l_system.add_production(predecessorA, successorAA);
        }
        catch (...) {
            exceptionThrown = true;
        }
        if (!exceptionThrown) {
            throw new std::exception("No exception was thrown");
        }
        }
    );

    test(++test_id, "L-system data access(axiom and successor)", []() {

        std::string axiom = "AB";
        char predecessorA = 'A';
        std::string successorAA = "AA";

        char predecessorB = 'B';
        std::string successorBB = "BB";


        LSystem<char, std::string> test_l_system;
        test_l_system.set_axiom(axiom);
        test_l_system.add_production(predecessorA, successorAA);
        test_l_system.add_production(predecessorB, successorBB);

        auto retAxiom = test_l_system.get_axiom();
        if (axiom.compare(*retAxiom) != 0) {
            throw new std::exception("Returned axiom incorrect");
        }

        auto retSuccessorAA = test_l_system.get_successor(predecessorA);
        if (successorAA.compare(*retSuccessorAA) != 0) {
            throw new std::exception("Returned successorAA incorrect");
        }

        auto retSuccessorBB = test_l_system.get_successor(predecessorB);
        if (successorBB.compare(*retSuccessorBB) != 0) {
            throw new std::exception("Returned successorBB incorrect");
        }
        
        }
    );

    test(++test_id, "L-system data access (successor not found)", []() {

        char predecessorA = 'A';
        std::string successorAA = "AA";
        char predecessorB = 'B';

        LSystem<char, std::string> test_l_system;
        test_l_system.add_production(predecessorA, successorAA);
        
        auto retSuccessorBB = test_l_system.get_successor(predecessorB);
        if (retSuccessorBB != nullptr) {
            throw new std::exception("Returned successor incorrect");
        }
        }
    );

    //testcases for wrong templates ??


    // LSYSTEM GENERATION TESTCASES

    test(++test_id, "L-system generation (including non terminals)", []() {

        // axiom
        std::string axiom = "A";

        // production 1
        char predecessorA = 'A';
        std::string successorAA = "BFB";

        // production 2
        char predecessorB = 'B';
        std::string successorBB = "AA";

        // result
        std::string expectedResult = "AAFAA";


        LSystem<char, std::string> test_l_system;
        test_l_system.set_axiom(axiom);
        test_l_system.add_production(predecessorA, successorAA);
        test_l_system.add_production(predecessorB, successorBB);

        // backinserter to save generation
        std::vector<char> result_l_system;
        auto backin = std::back_insert_iterator(result_l_system);

        // calculate generation
        calculate_l_system_generation<LSystem, char, std::string, std::back_insert_iterator<std::vector<char>>>(test_l_system, 2, backin);

        //check result
        for (std::size_t i = 0; i < result_l_system.size(); ++i) {
            
            if (expectedResult[i] != result_l_system[i]) {
                throw new std::exception("Generated result incorrect");
            }
        }

        }
    );

    // COMMAND MAPPING ITERATOR TESTCASES 

    test(++test_id, "CommandMappingIterator", []() {

        std::vector<char> command_list = { 'f', 'F', '+', '-' };

        SaveTurtle save_turtle;

        // use iterator
        CommandMappingIterator iter{ save_turtle };
        for (auto c : command_list) {
            *iter++ = c;
        }

        // control size
        auto size = save_turtle.commands.size();
        if (size != command_list.size()) {
            throw new std::exception("Iterator: amount of calls incorrect");
        }

        // control result
        for (std::size_t i = 0; i < size; ++i) {
            if (save_turtle.commands[i] != command_list[i]) {
               throw new std::exception("Iterator: commands not matching");
            }
        }

        // test rvalue assignment and pre increment
        *(++iter) = std::move('c');
        }
    );


    // TEST TURTLE TESTCASES 

    test(++test_id, "Test turle", []() {
        TestTurtle test_turtle;

        std::cout << std::endl << std::endl << "----------" << std::endl;
        test_turtle.draw();
        test_turtle.move();
        test_turtle.turn_left();
        test_turtle.turn_right();
        std::cout << "----------" << std::endl << std::endl;

        }
    );

    // CAIRO TURTLE TESTCASES

    test(++test_id, "Cairo turle", []() {
        CairoTurtle cairo_turtle;

        cairo_turtle.set_line_lenght(150.0);
        cairo_turtle.set_line_width(2.0);
        cairo_turtle.set_turning_angle(90);

        // sample calls which will be deleted
        cairo_turtle.draw();
        cairo_turtle.move();
        cairo_turtle.turn_right();
        cairo_turtle.turn_left();
        cairo_turtle.draw();

        // delet current data
        cairo_turtle.reset();

        // draw two rectangles
        cairo_turtle.draw();
        cairo_turtle.turn_right();
        cairo_turtle.draw();
        cairo_turtle.turn_right();
        cairo_turtle.draw();
        cairo_turtle.turn_right();
        cairo_turtle.draw();
        cairo_turtle.turn_right();
        cairo_turtle.draw();
        cairo_turtle.turn_left();
        cairo_turtle.draw();
        cairo_turtle.turn_left();
        cairo_turtle.draw();
        cairo_turtle.turn_left();
        cairo_turtle.draw();
        cairo_turtle.turn_left();
        cairo_turtle.draw();

        // fail the savin process with illegal filename
        bool excpetionThrown = false;
        try {

            cairo_turtle.save_to_png("//\\//\\two_rectangles.png");
        }
        catch (...) {
            excpetionThrown = true;
        }

        if (!excpetionThrown) {
            throw new std::exception("Save to png didn't return an exception for an impossible save process");
        }

        // correct save process
        cairo_turtle.save_to_png("two_rectangles.png");

        }
    );

    std::cout << "Tests completed" << std::endl;
 
    return 0;
}