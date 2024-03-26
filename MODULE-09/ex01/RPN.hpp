#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <queue>
# include <string>
# include <stdexcept>
# include <cctype>
# include <cstring>

class RPN {
	public:
		RPN(const char *expression);
		RPN(const RPN &other);
		RPN const &operator=(const RPN &rpn);
		~RPN();

		void calculate();
		void printNumbers();
		void printOperators();
		double getResult() const;

	private:
		RPN();
		std::queue<char> _numbers;
		std::queue<char> _operators;
		double _result;
};


#endif
