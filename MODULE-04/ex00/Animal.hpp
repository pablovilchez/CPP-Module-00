/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:39:32 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/17 01:03:18 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		std::string getType() const;

		virtual void makeSound() const;
	
	protected:
		std::string _type;
};

#endif
