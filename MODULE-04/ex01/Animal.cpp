/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:38:50 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/15 19:50:19 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal& other)
{
	_type = other._type;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}

Animal& Animal::operator=(const Animal& other)
{
	_type = other._type;
	std::cout << "Animal assignation operator" << std::endl;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Some indistinguishable sound..." << std::endl;
}
