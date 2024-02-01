/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:56:58 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/01 22:37:18 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::get_first_name() {return (_first_name);}

std::string	Contact::get_last_name() {return (_last_name);}

std::string	Contact::get_nickname() {return (_nickname);}

void	Contact::set_first_name()
{
	std::cout << "** First name: ";
	std::getline(std::cin, _first_name);
	while (_first_name.empty() && !std::cin.eof())
	{
		std::cout << std::endl << "< Invalid input. Required field >" << std::endl;
		std::cout << std::endl << "** First name: ";
		std::getline(std::cin, _first_name);
	}
}

void	Contact::set_last_name()
{
	std::cout << "** Last name: ";
	std::getline(std::cin, _last_name);
	while (_last_name.empty() && !std::cin.eof())
	{
		std::cout << std::endl << "< Invalid input. Required field >" << std::endl;
		std::cout << std::endl << "** Last name: ";
		std::getline(std::cin, _last_name);
	}
}

void	Contact::set_nickname()
{
	std::cout << "** Nickname: ";
	std::getline(std::cin, _nickname);
	while (_nickname.empty() && !std::cin.eof())
	{
		std::cout << std::endl << "< Invalid input. Required field >" << std::endl;
		std::cout << std::endl << "** Nickname: ";
		std::getline(std::cin, _nickname);
	}
}

void	Contact::set_phone_number()
{
	std::cout << "** Phone number: ";
	std::getline(std::cin, _phone_number);
	while (_phone_number.empty() && !std::cin.eof())
	{
		std::cout << std::endl << "< Invalid input. Required field >" << std::endl;
		std::cout << std::endl << "** Phone number: ";
		std::getline(std::cin, _phone_number);
	}
}

void	Contact::set_darkest_secret()
{
	std::cout << "** Darkest secret: ";
	std::getline(std::cin, _phone_number);
	while (_phone_number.empty() && !std::cin.eof())
	{
		std::cout << std::endl << "< Invalid input. Required field >" << std::endl;
		std::cout << std::endl << "** Darkest secret: ";
		std::getline(std::cin, _phone_number);
	}
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