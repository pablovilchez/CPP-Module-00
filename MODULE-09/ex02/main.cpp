#include "PmergeMe.hpp"
# include <ctime>

int main(int argc, char **argv) {
	try {
		if (argc < 2) {
			throw std::invalid_argument("Usage: ./PmergeMe [int1] [int2] [int3] ...");
		}
		PmergeMe pmerge(argv);
		clock_t startV = clock();
		pmerge.sortVector();
		clock_t endV = clock();
		clock_t startL = clock();
		pmerge.sortList();
		clock_t endL = clock();
		std::cout << "Vector sort time for " << argc - 1 << " elements : ";
		std::cout << (double)(endV - startV) / CLOCKS_PER_SEC << "s" << std::endl;
		std::cout << "List sort time for " << argc - 1 << " elements : ";
		std::cout << (double)(endL - startL) / CLOCKS_PER_SEC << "s" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}