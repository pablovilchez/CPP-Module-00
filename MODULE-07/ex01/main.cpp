/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:36:01 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/25 21:03:34 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
T doubleValue(T value) {
    return value * 2;
}

template <typename T>
T addOne(T value) {
    return value + 1;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
	
    ::iter(intArray, 5, doubleValue);
    for (int i = 0; i < 5; ++i)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;

	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	::iter(floatArray, 5, doubleValue);
	for (int i = 0; i < 5; ++i)
		std::cout << floatArray[i] << " ";
	std::cout << std::endl;

	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(charArray, 5, addOne);
	for (int i = 0; i < 5; ++i)
		std::cout << charArray[i] << " ";
	std::cout << std::endl;
	
	return 0;
}