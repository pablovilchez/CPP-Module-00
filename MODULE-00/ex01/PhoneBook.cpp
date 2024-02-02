/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:33:25 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/01 22:38:25 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_index = 0;
}

void	PhoneBook::add_contact()
{
	_contacts[_index].set_contact();
	_index++;
	if (_index > 7)
		_index = 0;
}

void	PhoneBook::r_align(std::string str)
{
	int		spaces;

	spaces = 10 - str.length();
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	if (str.length() > 10)
		std::cout << (str.substr(0, 9) + ".");
	else
		std::cout << str;
}

void PhoneBook::print_phonebook()
{
	std::cout << std::endl << "-- Contact list --" << std::endl << std::endl;
	std::cout << "Index     |First name|Last name |Nickname  " << std::endl << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "         " << i << "|";
		r_align(_contacts[i].get_first_name());
		std::cout << "|";
		r_align(_contacts[i].get_last_name());
		std::cout << "|";
		r_align(_contacts[i].get_nickname());
		std::cout << std::endl << std::endl;
	}

}

void PhoneBook::search_contact()
{
	int			index;
	std::string	input;

	print_phonebook();
	std::cout << std::endl << "Enter index: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	if (input.length() == 0  || input.length() > 1 || !isdigit(input[0]))
	{
		std::cout << std::endl << "< Invalid index >" << std::endl;
		return ;
	}
	index = input[0] - '0';	
	if (index < 0 || index > 7)
	{
		std::cout << std::endl << "< Invalid index >" << std::endl;
		return ;
	}
	if (_contacts[index].get_first_name().length() == 0)
	{
		std::cout << std::endl << "< Empty Contact >" << std::endl;
		return ;
	}
	_contacts[index].print_contact();
}
