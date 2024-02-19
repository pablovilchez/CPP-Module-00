/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:54:36 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/19 10:21:48 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(const Ice &other) : AMateria("ice")
{}
		
Ice::~Ice()
{}

Ice& Ice::operator=(const Ice &other)
{
	return *this;
}

AMateria* Ice::clone() const
{
	Ice* new_ice = new Ice();
	return (new_ice);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}