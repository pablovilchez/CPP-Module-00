/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:53:26 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/15 13:23:47 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap default constructor (" << _name << ")" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap constructor (" << _name << ")" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "ScavTrap copy constructor (" << _name << ")" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor (" << _name << ")" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "ScavTrap assignation operator" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << _name << " attack " << target;
	std::cout << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " in Gate keeper mode" << std::endl;
}
