#include "RPN.hpp"

RPN::RPN(const char *expression) {
	const char *init = expression;
	const char *operators = "+-*/";
	while (*init) {
		if (!isdigit(*init) && !strchr(operators, *init) && *init != ' ')
			throw std::invalid_argument("Invalid character in expression.");
		if (isdigit(*init) && isdigit(*(init + 1)))
			throw std::invalid_argument("Numbers must be between 0 and 9.");
		if (*init != ' ' && (*(init + 1) != ' ' && *(init + 1) != '\0'))
			throw std::invalid_argument("Invalid format. Use spaces between numbers and operators.");
		init++;
	}
	while (*expression) {
		if (isdigit(*expression))
			_numbers.push(*expression - '0');
		else if (strchr(operators, *expression)) {
			if (_numbers.size() < 2)
				throw std::invalid_argument("Not enough numbers or invalid order.");
			float numB = _numbers.top();
			_numbers.pop();
			float numA = _numbers.top();
			_numbers.pop();
			_numbers.push(calculate(numA, numB, *expression));
		}
		expression++;
	}
	if (_numbers.empty() || _numbers.size() > 1)
		throw std::invalid_argument("Invalid expression.");
	_result = _numbers.top();
	std::cout << _result << std::endl;
}

RPN::~RPN() { }

float RPN::calculate(float numA, float numB, char operation) {
	switch (operation) {
		case '+':
			return (numA + numB);
		case '-':
			return (numA - numB);
		case '*':
			return (numA * numB);
		case '/':
			if (numB == 0)
				throw std::invalid_argument("Division by 0.");
			return (numA / numB);
		default:
			throw std::invalid_argument("Invalid operator.");
	}
}
