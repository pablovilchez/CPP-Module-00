/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:57:53 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/03 01:27:17 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 8;
	Zombie *z_horde = zombieHorde(N, "Paquito");	

	for (int i = 0; i < N; i++)
		z_horde[i].announce();
	delete [] z_horde;
	return 0;
}
