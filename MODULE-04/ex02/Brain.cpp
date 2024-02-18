/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:28:49 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/17 16:33:45 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain::~Brain()
{
	
}

Brain& Brain::operator=(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return *this;
}

void Brain::showIdeas()
{
	int i = 0;
	
	std::cout << "ideas:" << std::endl;
	while (_ideas[i][0])
	{
		std::cout << "  " << _ideas[i] << std::endl;
		i++;
	}
	if (i == 0)
		std::cout << "<empty brain>" << std::endl;
}

std::string Brain::getIdea(int pos) const
{
	return (_ideas[pos]);
}

void Brain::setIdea(int pos, std::string new_idea)
{
	_ideas[pos] = new_idea;
}