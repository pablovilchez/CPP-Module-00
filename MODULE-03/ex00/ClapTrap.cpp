/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:37:03 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/12 13:45:40 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "Constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "Constructor called for " << this->_name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for " << this->_name << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& other)
{
	
}
		
void ClapTrap::attack(const std::string& target)
{
	
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{
	
}