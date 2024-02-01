/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:58:15 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/01 22:35:53 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		void		set_contact();
		void		print_contact();
		void		set_first_name();
		void		set_last_name();
		void		set_nickname();
		void		set_phone_number();
		void		set_darkest_secret();
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
	
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif