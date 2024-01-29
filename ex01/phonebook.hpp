/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:42:34 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/29 22:34:54 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

class PhoneBook
{
	public:
		Contact		contacts[8];
		int			index;
		void		add_contact(int index);
		void		search_contact();
		void		print_contact_list(Contact contacts[8]);
		void		print_contact(Contact contact);

	PhoneBook() {index = 0;}
};


void PhoneBook::add_contact(int index)
{
	std::cout << "Add new contact" << std::endl;
	std::cout << "** First name: ";
	std::getline(std::cin, contacts[index].first_name);
	std::cout << "** Last name: ";
	std::getline(std::cin, contacts[index].last_name);
	std::cout << "** Nickname: ";
	std::getline(std::cin, contacts[index].nickname);
	std::cout << "** Phone number: ";
	std::getline(std::cin, contacts[index].phone_number);
	std::cout << "** Darkest secret: ";
	std::getline(std::cin, contacts[index].darkest_secret);
	index++;
	if (index > 7)
		index = 0;
	std::cout << "Contact added" << std::endl;
}

void PhoneBook::print_contact_list(Contact contacts[8])
{
	std::cout << "Contact list" << std::endl;
	std::cout << "Index     |First name|Last name |Nickname  " << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << i << "         |";
		if (contacts[i].first_name.length() > 10)
			std::cout << contacts[i].first_name.substr(0, 9) << ".|";
		else
			std::cout << contacts[i].first_name;
		if (contacts[i].last_name.length() > 10)
			std::cout << contacts[i].last_name.substr(0, 9) << ".|";
		else
			std::cout << contacts[i].last_name;
		if (contacts[i].nickname.length() > 10)
			std::cout << contacts[i].nickname.substr(0, 9) << ".|";
		else
			std::cout << contacts[i].nickname;
		std::cout << std::endl;
	}

}

void PhoneBook::print_contact(Contact contact)
{
	std::cout << std::endl;
	std::cout << "Contact info" << std::endl;
	std::cout << "** First name: " << contact.first_name << std::endl;
	std::cout << "** Last name: " << contact.last_name << std::endl;
	std::cout << "** Nickname: " << contact.nickname << std::endl;
	std::cout << "** Phone number: " << contact.phone_number << std::endl;
	std::cout << "** Darkest secret: " << contact.darkest_secret << std::endl;
}

void PhoneBook::search_contact()
{
	int			index;
	std::string	input;

	print_contact_list(contacts);
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	index = std::atol(input);
	if (index < 0 || index > 7)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (contacts[index].first_name.length() == 0)
	{
		std::cout << "Contact not found" << std::endl;
		return ;
	}
	print_contact(contacts[index]);
}