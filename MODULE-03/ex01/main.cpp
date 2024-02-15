/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:08:40 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/15 11:53:43 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("Paco");
	ClapTrap clap("Pepe");

	scav.attack("Pepe");
	scav.guardGate();
	clap.attack("Paco");

	
	
	return 0;
}