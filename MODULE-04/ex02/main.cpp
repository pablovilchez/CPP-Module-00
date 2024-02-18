/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:36:06 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/17 19:28:03 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int size = 10;
	Animal *animals[size];

	std::srand(std::time(0));
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	
	for (int i = 0; i < size; i++)
	{
		std::cout << animals[i]->getType() << " " << i / 2 + 1 << " ";
		animals[i]->readBrain();
	}
	
	for (int i = 0; i < size; i++)
		delete animals[i];
	
	return 0;
}

/*
int main()
{
	std::srand(std::time(0));

	const Animal* ginger = new Cat();
	std::cout << "Ginger ";
	ginger->readBrain();

	std::cout << std::endl;

	const Animal* ponyo = new Cat();
	std::cout << "Ponyo ";
	ponyo->readBrain();

	std::cout << std::endl;

	const Animal* p_clone = new Cat(*ponyo);
	std::cout << "Ponyo clone ";
	p_clone->readBrain();

	std::cout << std::endl;
	
	Animal* totoro = new Dog();
	std::cout << "Totoro ";
	totoro->readBrain();

	delete ginger;
	delete ponyo;
	delete p_clone;
	delete totoro;

	return 0;
}
*/