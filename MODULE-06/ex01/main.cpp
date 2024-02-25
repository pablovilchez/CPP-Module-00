/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:48:56 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/25 16:29:00 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	int ptr = 42;
	Data *stdPtr = new Data(ptr);
	uintptr_t intPtr = Serializer::serialize(stdPtr);
	Data *other = Serializer::deserialize(intPtr);

	std::cout << "Before: " << stdPtr->rawPtr << std::endl;
	std::cout << "after: " << other->rawPtr << std::endl;

	std::cout << "Before: " << std::hex << stdPtr << std::endl;
	std::cout << "after: " << std::hex << other << std::endl;
	
	delete stdPtr;
	return 0;
}