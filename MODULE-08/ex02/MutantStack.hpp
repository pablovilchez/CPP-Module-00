#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &other) : std::stack<T>(other) {}

        ~MutantStack() {}

        MutantStack &operator=(const MutantStack &other)
        {
            if (this == &other)
                return (*this);
            this->std::stack<T>::operator=(other);
            return (*this);
        }

        typedef typename std::deque<T>::iterator iterator;

        iterator begin() {
            return (std::stack<T>::c.begin());
        }
        iterator end() {
            return (std::stack<T>::c.end());
        }

		void printContainer() {
			std::cout << "Container: ";
			if (this->empty()) {
				std::cout << "empty" << std::endl;
				return;
			}
			else {
				for (iterator it = this->begin(); it != this->end(); it++)
					std::cout << *it << " ";
			}
			std::cout << std::endl;
		}
};

#endif