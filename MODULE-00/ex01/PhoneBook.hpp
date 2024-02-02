/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:42:34 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/01 22:37:30 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void		add_contact();
		void		search_contact();
		void		print_phonebook();
		void		r_align(std::string str);
	
	private:
		int			_index;
		Contact		_contacts[8];
};

#endif