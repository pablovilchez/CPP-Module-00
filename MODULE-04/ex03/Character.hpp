/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:49:07 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/19 21:04:56 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(const Character &other);
		Character(std::string name);
		
		~Character();

		Character &operator=(const Character &other);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		void initInventory();
		void seeInventory();
		void toGround(AMateria* m);
		void cleanGround();
		void seeGround();

	private:
		std::string _name;
		AMateria *_inventory[4];
		static AMateria * _ground[100];
};

#endif