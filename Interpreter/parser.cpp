#include "parser.h"

Parser::Parser(Lexer& lexer) : lexer_(lexer) {
    currentToken_ = lexer_.getNextToken();
}

void Parser::parse() {
    parseFilter();
}

void Parser::error(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
    exit(1);
}

void Parser::expect(TokenType type) {
    if (currentToken_.type != type) {
        error("Unexpected token");
    }
    currentToken_ = lexer_.getNextToken();
}

void Parser::parseFilter() {
    parseExpression();
    while (currentToken_.type == TokenType::AND_ || currentToken_.type == TokenType::OR_) {
        expect(currentToken_.type);
        parseExpression();
    }
}

void Parser::parseExpression() {
    parseTerm();
    while (currentToken_.type == TokenType::EQ || currentToken_.type == TokenType::NEQ ||
        currentToken_.type == TokenType::LT || currentToken_.type == TokenType::GT) {
        expect(currentToken_.type);
        parseTerm();
    }
}

void Parser::parseTerm() {
    if (currentToken_.type == TokenType::LPAREN) {
        expect(TokenType::LPAREN);
        parseExpression();
        expect(TokenType::RPAREN);
    }
    else if (currentToken_.type == TokenType::STRING) {
        std::cout << "Found string: " << currentToken_.value << std::endl;
        expect(TokenType::STRING);
    }
    else if (currentToken_.type == TokenType::NUMBER) {
        std::cout << "Found number: " << currentToken_.value << std::endl;
        expect(TokenType::NUMBER);
    }
    else {
        error("Unexpected token");
    }
}