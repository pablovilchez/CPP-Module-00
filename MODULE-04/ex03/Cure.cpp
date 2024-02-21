/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:55:43 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/21 10:06:09 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure &other) : AMateria("cure")
{}
		
Cure::~Cure()
{}

Cure& Cure::operator=(const Cure &other)
{
	return *this;
}

AMateria* Cure::clone() const
{
	Cure* new_ice = new Cure();
	return (new_ice);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
