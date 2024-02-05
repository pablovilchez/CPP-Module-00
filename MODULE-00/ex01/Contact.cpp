/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:56:58 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/05 17:10:47 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::~Contact()
{
	
}

std::string	Contact::get_first_name() {return (_first_name);}

std::string	Contact::get_last_name() {return (_last_name);}

std::string	Contact::get_nickname() {return (_nickname);}

void	Contact::set_first_name()
{
	do
	{
		std::cout << std::endl << "** First name: ";
		std::getline(std::cin, _first_name);
	} while (!check_string(_first_name));
}

void	Contact::set_last_name()
{
	do
	{
		std::cout << std::endl << "** Last name: ";
		std::getline(std::cin, _last_name);
	} while (!check_string(_last_name));
}

void	Contact::set_nickname()
{
	do
	{
		std::cout << std::endl << "** Nickname: ";
		std::getline(std::cin, _nickname);
	} while (!check_string(_nickname));
}

void	Contact::set_phone_number()
{
	do
	{
		std::cout << std::endl << "** Phone number: ";
		std::getline(std::cin, _phone_number);
	} while (!check_number(_phone_number));
}

void	Contact::set_darkest_secret()
{
	do
	{
		std::cout << std::endl << "** Darkest secret: ";
		std::getline(std::cin, _darkest_secret);
	} while (!check_string(_darkest_secret));
}


void	Contact::set_contact()
{
	std::cout << std::endl << "-- Add new contact --" << std::endl << std::endl;
	set_first_name();
	set_last_name();
	set_nickname();
	set_phone_number();
	set_darkest_secret();
	std::cout<< std::endl;
	if (std::cin.eof())
		std::cout << std::endl << "< Error adding contact >";
	else
		std::cout << "< Contact added >";
	std::cout << std::endl << std::endl;
}

void	Contact::print_contact()
{
	std::cout << std::endl << "-- Contact info --" << std::endl << std::endl;
	std::cout << "** First name: " << _first_name << std::endl;
	std::cout << "** Last name: " << _last_name << std::endl;
	std::cout << "** Nickname: " << _nickname << std::endl;
	std::cout << "** Phone number: " << _phone_number << std::endl;
	std::cout << "** Darkest secret: " << _darkest_secret << std::endl << std::endl;
}

bool	Contact::check_string(std::string input)
{
	if (std::cin.eof())
		return (true);
	if (input.empty())
	{
		std::cout << "< Invalid input. Required field >" << std::endl;
		return (false);
	}
	unsigned int len = input.length();
	for (unsigned int i = 0; i < len; i++)
	{
		if (!isalpha(input[i]))
		{
			std::cout << "< Invalid input. Only alphanumeric allowed >" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	Contact::check_number(std::string input)
{
	if (std::cin.eof())
		return (true);
	if (input.empty())
	{
		std::cout << "< Invalid input. Required field >" << std::endl;
		return (false);
	}
	unsigned int len = input.length();
	for (unsigned int i = 0; i < len; i++)
	{
		if (!isnumber(input[i]))
		{
			std::cout << "< Invalid input. Only numbers allowed >" << std::endl;
			return (false);
		}
	}
	return (true);
}