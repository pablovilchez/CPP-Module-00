/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:31:36 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/20 22:43:08 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor" << std::endl;
	_type = "Cat";
	_brain = new Brain();
	fillBrain(3);
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor" << std::endl;
	_type = other._type;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, other._brain->getIdea(i));
}

Cat::Cat(const Animal& other) : Animal(other)
{
	std::cout << "Cat casted copy constructor" << std::endl;
	const Cat* other_cat = dynamic_cast<const Cat*>(&other);
	if(other_cat)
	{
		_type = other_cat->_type;
		_brain = new Brain();
		for (int i = 0; i < 100; i++)
			_brain->setIdea(i, other_cat->_brain->getIdea(i));
	}
	else
		std::cerr << "Error: incorrect data cast";
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete (_brain);
}

Cat& Cat::operator=(const Cat& other)
{
	_type = other._type;
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, other._brain->getIdea(i));
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meooowwww" << std::endl;
}

void Cat::fillBrain(int num)
{
	std::string cat_ideas [10]= {"Purr", "Meow", "Pounce", "Scratch",
		"Lick", "Nap", "Hunt", "Stretch", "Cuddle", "Play"};
	
	for (int i = 0; i < num; i++)
		_brain->setIdea(i, cat_ideas[std::rand()%10]);
}

void Cat::readBrain() const
{
	_brain->showIdeas();
}