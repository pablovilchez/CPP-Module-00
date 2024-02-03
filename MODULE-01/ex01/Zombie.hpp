/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:58:13 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/02 22:45:58 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public:
		Zombie();
		~Zombie();
		void announce();
		void setName(std::string name);
		std::string getName();

	private:
		std::string name;
};

Zombie *newZombie(std::string name);

Zombie *zombieHorde(int N, std::string name);

#endif