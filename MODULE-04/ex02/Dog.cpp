/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:35:17 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/17 16:32:34 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	fillBrain(3);
}

Dog::Dog(const Dog& other)
{
	_type = other._type;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, other._brain->getIdea(i));
}

Dog::Dog(const Animal& other) : Animal(other)
{
	const Dog* other_dog = dynamic_cast<const Dog*>(&other);
	if(other_dog)
	{
		_type = other_dog->_type;
		_brain = new Brain();
		for (int i = 0; i < 100; i++)
			_brain->setIdea(i, other_dog->_brain->getIdea(i));
	}
	else
		std::cerr << "Error: incorrect data cast";
}

Dog::~Dog()
{
	delete (_brain);
}

Dog& Dog::operator=(const Dog& other)
{
	_type = other._type;
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, other._brain->getIdea(i));
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woofff" << std::endl;
}

void Dog::fillBrain(int num)
{
	std::string dog_ideas [10]= {"Bark", "Wag", "Fetch", "Chew", "Dig",
		"Roll over", "Beg", "Sniff", "Shake", "Guard"};
	
	for (int i = 0; i < num; i++)
		_brain->setIdea(i, dog_ideas[std::rand()%10]);
}

void Dog::readBrain() const
{
	_brain->showIdeas();
}