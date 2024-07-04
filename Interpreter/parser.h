#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

class Parser {
public:
    Parser(Lexer& lexer);
    void parse();

private:
    Lexer& lexer_;
    Token currentToken_;
    void error(const std::string& message);
    void expect(TokenType type);
    void parseFilter();
    void parseExpression();
    void parseTerm();
};

#endif // PARSER_H