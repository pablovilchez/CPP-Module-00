/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:36:06 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/15 19:47:59 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	std::cout << std::endl;

	const Animal* i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	std::cout << std::endl;

	const Animal* j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	
	return 0;
}