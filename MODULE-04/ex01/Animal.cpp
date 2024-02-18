/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:38:50 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/17 14:13:21 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
}

Animal::Animal(const Animal& other)
{
	_type = other._type;
}

Animal::~Animal()
{
	
}

std::string Animal::getType() const
{
	return _type;
}

Animal& Animal::operator=(const Animal& other)
{
	_type = other._type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Some indistinguishable sound..." << std::endl;
}

void Animal::readBrain() const
{
	std::cout << "This animal has not brain." << std::endl;
}
