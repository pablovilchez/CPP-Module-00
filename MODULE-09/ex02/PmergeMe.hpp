#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
#

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &src);

		PmergeMe &operator=(const PmergeMe &src);

		~PmergeMe();

		void printVector(std::vector<int> vec);
		void sortVector();
		std::vector<int> sortV(std::vector<int> vec);
		std::vector<int> mergeV(std::vector<int> vec1, std::vector<int> vec2);

		void printList(std::list<int> list);
		void sortList();
		std::list<int> sortL(std::list<int> list);
		std::list<int> mergeL(std::list<int> list1, std::list<int> list2);

	private:
		std::vector<int> _v;
		std::list<int> _l;

};


#endif
