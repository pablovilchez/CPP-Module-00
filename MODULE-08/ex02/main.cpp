#include "MutantStack.hpp"
# include <iostream>
# include <list>

int main()
{
    MutantStack<int> mstack;

	std::cout << "+++++ Empty stack +++++" << std::endl;
	mstack.printContainer();
	std::cout << std::endl;

	std::cout << "+++++ Push 5, 17, 3 +++++" << std::endl;
    mstack.push(5);
    mstack.push(17);
	mstack.push(3);
	mstack.printContainer();
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << "+++++ Top +++++" << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << std::endl;

	std::cout << "+++++ Pop +++++" << std::endl;
    mstack.pop();
	mstack.printContainer();
    std::cout << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << "+++++ Push 3, 5, 737, 0 +++++" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
	mstack.printContainer();
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << "+++++ Iterators test +++++" << std::endl;
    MutantStack<int>::iterator itBegin = mstack.begin();
    MutantStack<int>::iterator itEnd = mstack.end();
    ++itBegin;
    --itBegin;
    while (itBegin != itEnd)
	{
		std::cout << *itBegin << std::endl;
		++itBegin;
	}
	std::cout << std::endl;

	std::cout << "+++++ Working compare with List +++++" << std::endl;
	MutantStack<char> otherStack;
	std::list<char> list;
	list.push_back('4');
	list.push_back('2');
	list.push_back('M');
	list.push_back('L');
	list.push_back('G');
	otherStack.push('4');
	otherStack.push('2');
	otherStack.push('M');
	otherStack.push('L');
	otherStack.push('G');
	std::cout << "List: ";
	for (std::list<char>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Stack: ";
	for (MutantStack<char>::iterator it = otherStack.begin(); it != otherStack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

    return 0;
}