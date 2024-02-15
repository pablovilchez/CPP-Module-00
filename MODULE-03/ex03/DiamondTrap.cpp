/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:06:45 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/15 13:36:39 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	_name = "Default_clap_name";
	_hitpoints = FragTrap::_hitpoints;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap default constructor (" << _name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitpoints = FragTrap::_hitpoints;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap constructor " << _name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	_name = other._name;
	_hitpoints = other._hitpoints;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "DiamondTrap copy constructor " << _name << ")" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor " << _name << ")" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap & other) {
	_name = other._name;
	_hitpoints = other._hitpoints;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "DiamondTrap assignation operator" << _name << ")" << std::endl;
	return *this;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}