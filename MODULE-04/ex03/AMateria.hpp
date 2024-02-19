/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:59:22 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/19 09:19:38 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const &type);
		
		~AMateria();

		AMateria(const AMateria &other);

		AMateria &operator=(const AMateria &other);

		std::string const &getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
		
	protected:
		std::string _type;
};

#endif