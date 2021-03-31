#include <iostream>
#include <vector>
#include <exception>
#include "Token.hpp"



class NumberException : public std::exception {
};

class ExpressionException : public std::exception {
};

// function to return the whole digit (substr of the input string)
std::string getNumber(std::string number, int index) {

	int digitCounter = 0, decimalCounter = 0;
	bool decimalNumber = false, zeroNumber = false;

	if (number[0] == 0) {
		zeroNumber = true;
	}


	for (int i = index; i < number.length(); i++) {
		if (isdigit(number[i])) {
			digitCounter += 1;
		}
		else if (number[i] == '.') {
			decimalNumber = true;
			decimalCounter += 1;
			digitCounter += 1;
		}
		else {
			break;
		}
		
	}
	if (zeroNumber == true && digitCounter > 1) {
		throw NumberException();
	}
	double tokenValue = stod(number.substr(index, digitCounter));
	std::string tokenString = number.substr(index, digitCounter);

	if (decimalCounter > 1 || (decimalNumber && tokenValue > 1.0) ||
		    (tokenString[tokenString.length() - 1] == '.') ) {
		throw NumberException();
	}

	return number.substr(index, digitCounter);
}

std::vector<Token> analyse(std::string input) {
	std::vector<Token> tokens;
	std::string buffer = "";
	TokenType tokenType;
	int operatorCounter = 0, numberCounter = 0;


	// loop iterates the string and sets the current states according to the indexes of the input
	for (int i = 0; i < input.length(); i++) {

		// buffers/counters needs to be reset if state is not the same
		if (!isdigit(input[i])) {
			buffer = "";
			numberCounter = 0;
		}
		if (isdigit(input[i])) {
			operatorCounter = 0;
		}

		if (isdigit(input[i])) {
			tokenType = Number;
			numberCounter += 1;
			buffer += getNumber(input, i);
			// index position of the loop needs to be changed if a multi digit number 
			// has been detected - to prevent extra tokens from being pushed back
			i += buffer.length() - 1;
			tokens.push_back(Token(std::stod(buffer)));
		}
		else if ((!isdigit(input[0]) && input[0] != '.') || !isdigit(input[input.length() - 1])) {
			throw ExpressionException();
		}
		else if (input[i] == '+') {
			operatorCounter += 1;
			tokens.push_back(tokenType = Plus);
		}
		else if (input[i] == '-') {
			operatorCounter += 1;
			tokens.push_back(tokenType = Minus);
		}
		else if (input[i] == '/') {
			operatorCounter += 1;
			tokens.push_back(tokenType = Divide);
		}
		else if (input[i] == '*') {
			operatorCounter += 1;
			tokens.push_back(tokenType = Times);
		} 
    	else if (input[i] == '.') {
      		throw NumberException();
    	}
		else if (tokenType == Number && input[i] == ' ') {
			numberCounter += 1;
		}
		if (operatorCounter > 1) {
			throw ExpressionException();
		}
		if (numberCounter > 1) {
			throw ExpressionException();
		}
	}

	return tokens;
}
