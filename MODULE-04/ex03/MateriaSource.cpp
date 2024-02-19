/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:26:25 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/19 20:45:06 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
		source[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.source[i])
			source[i] = other.source[i]->clone();
		else
			source[i] = nullptr;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
			delete source[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.source[i])
		{
			if (source[i])
				delete source[i];
			source[i] = other.source[i]->clone();
		}
		else
		{
			if (source[i])
				delete source[i];
			source[i] = nullptr;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* new_mat)
{
	bool dup = false;
	int free_space = -1;
	
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
		{
			if (source[i]->getType() == new_mat->getType())
				dup = true;
		}
		else if (free_space < 0)
			free_space = i;
	}
	if (dup)
	{
		std::cout << "* The book already contains that spell *" << std::endl;
		delete new_mat;
	}
	else if (free_space < 0)
	{
		std::cout << "* The book is already full *" << std::endl;
		delete new_mat;
	}
	else
		source[free_space] = new_mat;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria * new_mat;
	for (int i = 0; i < 4; i++)
	{
		if (source[i]->getType() == type)
		{
			new_mat = source[i]->clone();
			return new_mat;
		}
	}
	std::cout << "* Materia not found *" << std::endl;
	return nullptr;
}

void MateriaSource::printBook()
{
	std::cout << std::endl << "MATERIA SOURCE:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			std::cout << source[i]->getType() << std::endl;
		else
			std::cout << "< empty >" << std::endl;
	}
	std::cout << std::endl;
}