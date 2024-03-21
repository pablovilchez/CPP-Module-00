#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
#include <climits>
#include <cmath>
#include <exception>
#include <vector>
#include <iostream>
#include <sstream>

class Span {
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);

        ~Span();

        Span &operator=(const Span &other);

        void addNumber(int num);
        void addRange(int start, int end);
        std::string shortestSpan();
        std::string longestSpan();

    private:
        unsigned int _numElem;
        std::vector<int> _cont;
};


#endif
