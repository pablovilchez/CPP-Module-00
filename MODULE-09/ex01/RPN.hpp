#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <queue>
# include <string>
# include <stdexcept>
# include <cctype>
# include <cstring>
# include <stack>

class RPN {
	public:
		RPN(const char *expression);
		~RPN();
		float calculate(float numA, float numB, char operation);

	private:
		RPN();
		RPN(const RPN &other);
		RPN const &operator=(const RPN &rpn);
		std::stack<float> _numbers;
		float _result;
};


#endif
