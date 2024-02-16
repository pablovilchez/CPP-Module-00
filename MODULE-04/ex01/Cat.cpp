/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:31:36 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/16 16:44:27 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat& other)
{
	_type = other._type;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	_type = other._type;
	std::cout << "Cat assignation operator" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meooowwww" << std::endl;
}
