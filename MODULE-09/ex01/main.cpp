#include "RPN.hpp"

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return 1;
	}
	try {
		RPN rpn(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	} catch (std::invalid_argument &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}