#include "Span.hpp"
#include <iostream>

std::vector<int> generateRandomRange(int size) {
	std::vector<int> range;
	for (int i = 0; i < size; i++) {
		range.push_back(rand() % 10000);
	}
	return range;
}

int main()
{
    std::cout << "+++++ Test without errors +++++" << std::endl;
	Span sp1(5);
    sp1.addNumber(6);
    sp1.addNumber(3);
    sp1.addNumber(17);
    sp1.addNumber(9);
    sp1.addNumber(1);
    std::cout << "shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp1.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "+++++ Test with size 0 (size error) +++++" << std::endl;
	Span sp2(0);
    sp2.addNumber(1);
    std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp2.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "+++++ Test with one element (size error) +++++" << std::endl;
    Span sp3(5);
    sp3.addNumber(1);
    std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp3.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "+++++ Test with 5 elements (size error) +++++" << std::endl;
	Span sp4(4);
	sp4.addNumber(1);
	sp4.addNumber(2);
	sp4.addNumber(3);
	sp4.addNumber(4);
	sp4.addNumber(5);
	std::cout << "shortest span: " << sp4.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp4.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "+++++ Test with ranges +++++" << std::endl;
    Span sp5(20000);
	std::vector<int> range = generateRandomRange(200);
	sp5.addRange(range.begin(), range.end());
	std::vector<int> range2 = generateRandomRange(20000);
	sp5.addRange(range2.begin(), range2.end());
	std::cout << "shortest span: " << sp5.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp5.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "+++++ Generated range +++++" << std::endl;
	for_each(range.begin(), range.end(), [](int &num) {
		std::cout << num << " "; });
	std::cout << std::endl;

    return 0;
}