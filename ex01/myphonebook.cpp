/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myphonebook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:05:34 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/29 22:21:21 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"



int main()
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "FUTURTEC Inc. -since 1981 making your life easier-" << std::endl;
	std::cout << "Welcome to your favourite MyPhoneBook v.0.1" << std::endl;
	std::cout << "Now with improved memory. Up to 8 contacts!!!" << std::endl;
	while (1)
	{
		std::cout << std::endl;
		std::cout << "<< MAIN MENU >> (You can ADD, SEARCH or EXIT)" << std::endl;
		std::cout << "Enter a command >> ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact(phonebook.index);
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
