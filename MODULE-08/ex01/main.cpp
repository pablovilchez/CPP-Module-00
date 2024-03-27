#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(1);
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;

    Span sp2(5);
    sp2.addNumber(1);
    std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp2.longestSpan() << std::endl;

    Span sp3(20000);

    sp3.addRange(1, 20000);
    std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp3.longestSpan() << std::endl;

    Span sp4(0);
    sp.addNumber(1);
    std::cout << "shortest span: " << sp4.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp4.longestSpan() << std::endl;

    return 0;
}