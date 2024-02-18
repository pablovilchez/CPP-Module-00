/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:35:39 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/17 15:01:05 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog(const Animal& other);
		~Dog();

		Dog& operator=(const Dog& other);

		void makeSound() const;

		void fillBrain(int num);
		void readBrain() const;
	
	private:
		Brain *_brain;
};

#endif