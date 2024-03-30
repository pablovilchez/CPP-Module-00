#include "Span.hpp"

Span::Span() : _numElem(0) { }

Span::Span(unsigned int N) : _numElem(N) { }

Span::Span(const Span &other) {
    this->_numElem = other._numElem;
    this->_cont = other._cont;
}

Span::~Span() { }

Span &Span::operator=(const Span &other) {
    if (this == &other)
        return *this;
    this->_numElem = other._numElem;
    this->_cont.clear();
    this->_cont = other._cont;
    return *this;
}

void Span::addNumber(int num) {
    try {
        if (this->_cont.size() < this->_numElem)
            this->_cont.push_back(num);
        else
            throw std::runtime_error("Not enough space to add number.");
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    try {
        if (this->_cont.size() + std::distance(start, end) <= this->_numElem) {
            this->_cont.insert(this->_cont.end(), start, end);
        } else {
            throw std::runtime_error("Not enough space to add range.");
        }
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::string Span::shortestSpan() {
    std::stringstream response;
	std::sort(this->_cont.begin(), this->_cont.end());
	int min = INT_MAX;
    try {
        if (this->_cont.size() < 2)
            throw std::runtime_error("Not enough elements to calculate span.");
		for (std::vector<int>::iterator it = this->_cont.begin(); it != std::prev(this->_cont.end(), 1); it++) {
			int diff = *(std::next(it, 1)) - *it;
			if (diff < min)
				min = diff;
		}
        response << min;
	}
    catch (std::exception &e) {
        response << "Error: " << e.what();
    }
    return response.str();
}

std::string Span::longestSpan() {
    std::stringstream response;
	std::sort(this->_cont.begin(), this->_cont.end());
    try {
        if (this->_cont.size() < 2)
            throw std::runtime_error("Not enough elements to calculate span.");
        response << *(this->_cont.end() - 1) - *(this->_cont.begin());
    } catch (std::exception &e) {
        response << "Error: " << e.what();
    }
    return response.str();
}
