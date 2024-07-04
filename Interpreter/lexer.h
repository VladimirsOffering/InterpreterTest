#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <vector>

enum class TokenType {
    UNKNOWN,
    STRING,
    NUMBER,
    GT,
    LT,
    EQ,
    NEQ,
    LPAREN,
    RPAREN,
    AND_,
    OR_
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string& input);
    Token getNextToken();
    bool hasNextToken();

private:
    std::string input_;
    size_t pos_;
    Token currentToken_;
};

#endif // LEXER_H