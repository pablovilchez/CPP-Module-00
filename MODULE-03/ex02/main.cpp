/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:08:40 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/15 08:59:06 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap("Paco");
	ScavTrap scav("Pepe");
	FragTrap frag("Tito");

	clap.attack("Pepe");
	scav.guardGate();
	scav.attack("Paco");
	frag.attack("Pepe");
	scav.beRepaired(10);
	frag.highFivesGuys();
	clap.takeDamage(20);
	
	return 0;
}