/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:12:11 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/13 21:53:30 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor (" << _name << ")" << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor (" << _name << ")" << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

FragTrap::FragTrap(const FragTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor (" << _name << ")" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap assignation operator" << std::endl;
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap " << _name << " attack " << target;
	std::cout << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "High fives guys!!" << std::endl;
}
