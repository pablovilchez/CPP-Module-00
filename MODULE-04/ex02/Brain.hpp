/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:28:23 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/17 15:16:51 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		
		~Brain();

		Brain& operator=(const Brain& other);

		void showIdeas();
		std::string getIdea(int pos) const;
		void setIdea(int pos, std::string new_idea);

	private:
		std::string _ideas[100];
		
};

#endif