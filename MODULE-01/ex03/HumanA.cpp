/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:46:42 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/03 14:58:14 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(&weapon)
{
	this->_name = name;
}

HumanA::~HumanA()
{
	
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}
