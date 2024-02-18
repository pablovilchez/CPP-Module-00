/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:12:11 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/16 23:53:26 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap default constructor (" << _name << ")" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap constructor (" << _name << ")" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "FragTrap copy constructor (" << _name << ")" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor (" << _name << ")" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "FragTrap assignation operator" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if(_energy_points > 0 && _hit_points > 0)
	{
		_energy_points--;
		std::cout << "FragTrap " << _name << " attack " << target;
		std::cout << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << _name << " stay still. Doesn't have enough ";
		std::cout << "health/energy." << std::endl;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout << _name << " says: High fives guys!!" << std::endl;
}
