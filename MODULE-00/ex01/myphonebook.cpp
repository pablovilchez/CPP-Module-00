/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myphonebook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:05:34 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/19 11:47:45 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << std::endl;
	std::cout << "FUTURTEC Inc. -since 1981 making your life easier-" << std::endl;
	std::cout << "Welcome to your favourite MyPhoneBook v.0.1" << std::endl;
	std::cout << "Now with improved memory. Up to 8 contacts!!!" << std::endl;
	while (1)
	{
		std::cout << std::endl;
		std::cout << "_____ MAIN MENU _____    ";
		std::cout << "(Type ADD, SEARCH or EXIT)" << std::endl << std::endl;
		std::cout << "Enter a command >> ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
		{
			std::cout << std::endl;
			break ;
		}
		else if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "Bye bye" << std::endl << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
