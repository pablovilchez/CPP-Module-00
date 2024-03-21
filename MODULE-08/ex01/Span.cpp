#include "Span.hpp"

Span::Span() : _numElem(0) { }

Span::Span(unsigned int N) : _numElem(N) { }

Span::Span(const Span &other) {
    this->_numElem = other._numElem;
    std::vector<int>::const_iterator it;
    for (it = other._cont.begin(); it != other._cont.end(); it++)
        this->_cont.push_back(*it);
}

Span::~Span() { }

Span &Span::operator=(const Span &other) {
    if (this == &other)
        return *this;
    this->_numElem = other._numElem;
    this->_cont.clear();
    std::vector<int>::const_iterator it;
    for (it = other._cont.begin(); it != other._cont.end(); it++)
        this->_cont.push_back(*it);
    return *this;
}

void Span::addNumber(int num) {
    try {
        if (this->_cont.size() < this->_numElem)
            this->_cont.push_back(num);
        else
            throw std::runtime_error("Not enough space to add number.");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Span::addRange(int start, int end) {
    try {
        if (this->_cont.size() + (end - start) <= this->_numElem) {
            for (int i = start; i <= end; i++)
                addNumber(i);
        } else {
            throw std::runtime_error("Not enough space to add range.");
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

std::string Span::shortestSpan() {
    std::stringstream response;
    try {
        if (this->_cont.size() < 2)
            throw std::runtime_error("Not enough elements to calculate span.");
        int min = INT_MAX;
        for (unsigned int i = 0; i < this->_cont.size(); i++) {
            for (unsigned int j = i + 1; j < this->_cont.size(); j++) {
                int diff = abs(this->_cont[i] - this->_cont[j]);
                if (diff < min)
                    min = diff;
            }
        }
        response << min;
    } catch (std::exception &e) {
        response << "Error: " << e.what();
    }
    return response.str();
}

std::string Span::longestSpan() {
    std::stringstream response;
    try {
        if (this->_cont.size() < 2)
            throw std::runtime_error("Not enough elements to calculate span.");
        int max = INT_MIN;
        for (unsigned int i = 0; i < this->_cont.size(); i++) {
            for (unsigned int j = i + 1; j < this->_cont.size(); j++) {
                int diff = abs(this->_cont[i] - this->_cont[j]);
                if (diff > max)
                    max = diff;
            }
        }
        response << max;
    } catch (std::exception &e) {
        response << "Error: " << e.what();
    }
    return response.str();
}
