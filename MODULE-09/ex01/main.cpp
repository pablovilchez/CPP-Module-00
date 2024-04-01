#include "RPN.hpp"

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		std::cout << "Error: Usage: " << argv[0] << " \"<expression>\"" << std::endl;
		return 1;
	}
	try {
		RPN rpn(argv[1]);
	} catch (std::invalid_argument &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}