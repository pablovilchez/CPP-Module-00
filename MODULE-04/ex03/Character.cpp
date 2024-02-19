/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:48:55 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/19 21:18:39 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

AMateria * Character::_ground[100] = {nullptr};

Character::Character() : _name("unknown")
{
	initInventory();
}

Character::Character(const Character &other)
{
	_name = other._name;
	initInventory();
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
}

Character::Character(std::string name) : _name(name)
{
	initInventory();
}
		
Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

Character & Character::operator=(const Character & other)
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	_name = other._name;
	initInventory();
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	int free_space = -1;
	
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (free_space < 0 && !_inventory[i])
				free_space = i;
		}
		if (free_space < 0)
		{
			std::cout << "* The inventory is already full *" << std::endl;
			toGround(m);
		}
		else
			_inventory[free_space] = m;
	}
	else
		std::cout << "Unequipped object. Incorrect reference." << std::endl;
}

void Character::unequip(int idx)
{
	if (_inventory[idx])
	{
		toGround(_inventory[idx]);
		_inventory[idx] = nullptr;
	}
	else
		std::cout << "* There is nothing in that pocket *" << std::endl; 
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "* There is nothing in that pocket *" << std::endl; 
}

void Character::initInventory()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

void Character::seeInventory()
{
	std::cout << std::endl << "INVENTORY: (" << _name << ")" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			std::cout << _inventory[i]->getType() << std::endl;
		else
			std::cout << "< empty >" << std::endl;
	}
	std::cout << std::endl;
}

void Character::toGround(AMateria* m)
{
	int i = 0;
	while (_ground[i] && i < 100)
		i++;
	if (i == 100)
	{
		std::cout << "Stack Error: The ground cannot store more than 100 items." << std::endl;
		delete m;
	}
	else
		_ground[i] = m;
}

void Character::cleanGround()
{
	for (int i = 0; i < 100; i++)
	{
		delete _ground[i];
		_ground[i] = nullptr;
	}
}

void Character::seeGround()
{
	bool empty = 1;

	std::cout << std::endl << "GROUND:" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (_ground[i])
		{
			std::cout << _ground[i]->getType() << std::endl;
			empty = 0;
		}
	}
	if (empty)
		std::cout << "< empty >" << std::endl;
	std::cout << std::endl;
}