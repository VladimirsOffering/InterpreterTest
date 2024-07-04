// Interpreter.cpp: определяет точку входа для приложения.
//

#include "Interpreter.h"
#include "parser.h"

int main() {
    std::string input;
    std::cout << "Enter a filter expression: ";
    std::getline(std::cin, input);

    Lexer lexer(input);
    Parser parser(lexer);
    parser.parse();

    return 0;
}