#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(char **argv) {
	int i = 1;
	int num;
	while (argv[i]) {
		num = atoi(argv[i]);
		if (num <= 0)
			throw std::invalid_argument("Invalid argument. Only positive integers.");
		_v.push_back(num);
		_l.push_back(num);
		i++;
	}
	std::cout << "Before: ";
	printVector(_v);
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	_v = other._v;
	_l = other._l;
	return *this;
}

PmergeMe::~PmergeMe() { }

void PmergeMe::printVector(std::vector<int> vec) {
	for (std::vector<int>::const_iterator itV = vec.begin(); itV != vec.end(); itV++) {
		std::cout << *itV << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList(std::list<int> list) {
	for (std::list<int>::const_iterator itL = list.begin(); itL != list.end(); itL++) {
		std::cout << *itL << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortVector() {
	std::vector<int> vecRes = sortV(_v);
	std::cout << "After: ";
	printVector(vecRes);
}

std::vector<int> PmergeMe::sortV(std::vector<int> vec) {
	std::vector<int> vecRes;
	if (vec.size() == 1) {
		vecRes.push_back(vec[0]);
		return vecRes;
	}
	std::vector<int> vec1;
	std::vector<int> vec2;
	for (int i = 0; i < vec.size(); i++) {
		if (i < vec.size() / 2) {
			vec1.push_back(vec[i]);
		} else {
			vec2.push_back(vec[i]);
		}
	}
	vec1 = sortV(vec1);
	vec2 = sortV(vec2);
	vecRes = mergeV(vec1, vec2);
	return vecRes;
}

std::vector<int> PmergeMe::mergeV(std::vector<int> vec1, std::vector<int> vec2) {
	std::vector<int> vecRes;
	int i = 0;
	int j = 0;
	while (i < vec1.size() && j < vec2.size()) {
		if (vec1[i] < vec2[j]) {
			vecRes.push_back(vec1[i]);
			i++;
		} else {
			vecRes.push_back(vec2[j]);
			j++;
		}
	}
	while (i < vec1.size()) {
		vecRes.push_back(vec1[i]);
		i++;
	}
	while (j < vec2.size()) {
		vecRes.push_back(vec2[j]);
		j++;
	}
	return vecRes;
}

void PmergeMe::sortList() {
	std::list<int> listRes = sortL(_l);
}

std::list<int> PmergeMe::sortL(std::list<int> list) {
	std::list<int> listRes;
	if (list.size() == 1) {
		listRes.push_back(list.front());
		return listRes;
	}
	std::list<int> list1;
	std::list<int> list2;
	int i = 0;
	for (std::list<int>::const_iterator itL = list.begin(); itL != list.end(); itL++) {
		if (i < list.size() / 2) {
			list1.push_back(*itL);
		} else {
			list2.push_back(*itL);
		}
		i++;
	}
	list1 = sortL(list1);
	list2 = sortL(list2);
	listRes = mergeL(list1, list2);
	return listRes;
}

std::list<int> PmergeMe::mergeL(std::list<int> list1, std::list<int> list2) {
	std::list<int> listRes;
	std::list<int>::const_iterator it1 = list1.begin();
	std::list<int>::const_iterator it2 = list2.begin();
	while (it1 != list1.end() && it2 != list2.end()) {
		if (*it1 < *it2) {
			listRes.push_back(*it1);
			it1++;
		} else {
			listRes.push_back(*it2);
			it2++;
		}
	}
	while (it1 != list1.end()) {
		listRes.push_back(*it1);
		it1++;
	}
	while (it2 != list2.end()) {
		listRes.push_back(*it2);
		it2++;
	}
	return listRes;
}