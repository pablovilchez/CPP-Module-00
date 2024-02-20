/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:35:17 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/20 22:44:35 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor" << std::endl;
	_type = other._type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	_type = other._type;
	std::cout << "Dog assignation operator" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woofff" << std::endl;
}
