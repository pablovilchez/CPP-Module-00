/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:48:55 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/18 00:41:46 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("unknown")
{
	init_inventory();
}

Character::Character(const Character &other)
{
	
}

Character::Character(std::string name) : _name(name)
{
	init_inventory();
}
		
Character::~Character()
{
	
}
		
std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{}

void Character::unequip(int idx)
{}

void Character::use(int idx, ICharacter& target)
{}

void Character::init_inventory()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}