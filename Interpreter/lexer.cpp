#include "lexer.h"

Lexer::Lexer(const std::string& input) : input_(input), pos_(0) {}

Token Lexer::getNextToken() {
	if (!hasNextToken()) {
		return Token{ TokenType::UNKNOWN, "" };
	}

	while (pos_ < input_.size() && std::isspace(input_[pos_])) {
		pos_++;
	}

	if (pos_ == input_.size()) {
		return Token{ TokenType::UNKNOWN, "" };
	}

	if (input_[pos_] == '(') {
		return Token{ TokenType::LPAREN, "(" };
	}
	else if (input_[pos_] == ')') {
		return Token{ TokenType::RPAREN, ")" };
	}
	else if (input_[pos_] == '>') {
		pos_++;
		return Token{ TokenType::GT, ">" };

	}
	else if (input_[pos_] == '<') {
		pos_++;
		return Token{ TokenType::LT, "<" };

	}
	else if (input_[pos_] == '=') {
		if (pos_ + 1 < input_.size() && input_[pos_ + 1] == '=') {
			pos_ += 2;
			return Token{ TokenType::EQ, "==" };
		}
		else {
			pos_++;
			return Token{ TokenType::UNKNOWN, "" };
		}
	}
	else if (input_[pos_] == '!') {
		if (pos_ + 1 < input_.size() && input_[pos_ + 1] == '=') {
			pos_ += 2;
			return Token{ TokenType::NEQ, "!=" };
		}
		else {
			pos_++;
			return Token{ TokenType::UNKNOWN, "" };
		}
	}
	else if (std::isdigit(input_[pos_])) {
		size_t start = pos_;
		while (pos_ < input_.size() && std::isdigit(input_[pos_])) {
			pos_++;
		}
		return Token{ TokenType::NUMBER, input_.substr(start, pos_ - start) };
	}
	else {
		size_t start = pos_;
		while (pos_ < input_.size() && !std::isspace(input_[pos_]) && input_[pos_] != '(' && input_[pos_] != ')') {
			pos_++;
		}
		return Token{ TokenType::STRING, input_.substr(start, pos_ - start) };
	}
}

bool Lexer::hasNextToken() {
	return pos_ < input_.size();
}