/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:26:12 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/19 20:27:36 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);

		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &other);
		
		void learnMateria(AMateria* new_mat);
		AMateria* createMateria(std::string const & type);
		
		void printBook();
	
	private:
		AMateria *source[4];
};

#endif