#include "PmergeMe.hpp"


int main(int argc, char **argv) {
	try {
		if (argc < 2)
			throw std::invalid_argument("Usage: ./PmergeMe [int1] [int2] [int3] ...");
		PmergeMe pmerge(argv);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}