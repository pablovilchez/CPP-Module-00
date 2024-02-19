/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:59:12 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/19 20:05:45 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Unrecognized")
{}

AMateria::AMateria(std::string const &type) : _type(type)
{}

AMateria::~AMateria()
{}


AMateria::AMateria(const AMateria &other)
{}

AMateria& AMateria::operator=(const AMateria &other)
{
	return *this;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* fail trying to use a unrecognized Materia element *" << std::endl;
}
