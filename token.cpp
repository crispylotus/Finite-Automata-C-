#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

enum TokenType { Number, Plus, Minus, Times, Divide, None };

TokenType typeOf(char op) {
	switch (op) {
	case '+':
		return Plus;
	case '-':
		return Minus;
	case '*':
		return Times;
	case '/':
		return Divide;
	case '0':
		return Number;
	case '1':
		return Number;
	case '2':
		return Number;
	case '3':
		return Number;
	case '4':
		return Number;
	case '5':
		return Number;
	case '6':
		return Number;
	case '7':
		return Number;
	case '8':
		return Number;
	case '9':
		return Number;
	default:
		return None;
	}
}

std::string typeToString(TokenType type) {
	switch (type) {
	case Number:
		return "Number";
	case Plus:
		return "Plus";
	case Minus:
		return "Minus";
	case Times:
		return "Times";
	case Divide:
		return "Divide";
	case '0':
		return "Number";
	case '1':
		return "Number";
	case '2':
		return "Number";
	case '3':
		return "Number";
	case '4':
		return "Number";
	case '5':
		return "Number";
	case '6':
		return "Number";
	case '7':
		return "Number";
	case '8':
		return "Number";
	case '9':
		return "Number";
	default:
		return "Error";
	}
}

class Token {

private:

	TokenType type;
	double value;

public:

	Token(TokenType type) {
		this->type = type;
		this->value = -1;
	}

	Token(double value) {
		this->type = Number;
		this->value = value;
	}

	bool isNumber() const {
		return this->type == Number;
	}

	double getValue() const {
		return this->value;
	}

	TokenType getType() const {
		return this->type;
	}

	friend std::ostream& operator<<(std::ostream&, const Token&);

};

std::ostream& operator<<(std::ostream& stream, const Token& t) {
	stream << typeToString(t.type);
	if (t.isNumber()) stream << ": " << t.value;
	return stream;
}

#endif
