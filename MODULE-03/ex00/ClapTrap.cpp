/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:37:03 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/13 18:57:06 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "default";
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "ClapTrap default constructor (" << _name << ")" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "ClapTrap constructor (" << _name << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "ClapTrap copy constructor (" << _name << ")" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor (" << _name << ")" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& other)
{
	std::cout << "ClapTrap assignation operator" << std::endl;
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	return *this;
}
		
void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << _name << " attack " << target;
	std::cout << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " take " << amount << " points of damage!" << std::endl;
	_hit_points -= amount;
	if (_hit_points < 0)
		_hit_points = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " be repaired " << amount << " points of damage!" << std::endl;
	_hit_points += amount;
	if (_hit_points > 10)
		_hit_points = 10;
}