#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const char *expression) {
	const char *init = expression;
	const char *operators = "+-*/";
	while (*init) {
		if (!isdigit(*init) && !strchr(operators, *init) && *init != ' ')
			throw std::invalid_argument("Invalid character in expression");
		init++;
	}
	while (*expression) {
		if (isdigit(*expression))
			_numbers.push(*expression);
		else if (strchr(operators, *expression))
			_operators.push(*expression);
		if (_operators.size() >= _numbers.size())
			throw std::invalid_argument("Too many operators");
		expression++;
	}
	if (_numbers.empty() || _operators.empty())
		throw std::invalid_argument("Operators or numbers missing");
	if (_numbers.size() != _operators.size() + 1)
		throw std::invalid_argument("Invalid operators/numbers count");
	calculate();
}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN const &RPN::operator=(const RPN &rpn) {
	_numbers = rpn._numbers;
	_operators = rpn._operators;
	_result = rpn._result;
	return *this;
}

RPN::~RPN() { }

void RPN::calculate() {
	if (_numbers.empty() || _operators.empty())
		throw std::invalid_argument("Nothing to calculate");
	_result = _numbers.front() - '0';
	_numbers.pop();
	while (!_numbers.empty()) {
		char operation = _operators.front();
		_operators.pop();
		double number = _numbers.front() - '0';
		_numbers.pop();
		switch (operation) {
			case '+':
				_result += number;
				break;
			case '-':
				_result -= number;
				break;
			case '*':
				_result *= number;
				break;
			case '/':
				_result /= number;
				break;
		}
	}
}

double RPN::getResult() const {
	return _result;
}