/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:33:35 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/27 14:21:26 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <iterator>

template<typename T>
void easyfind(const T &cont, int num)
{
	typedef typename T::const_iterator iter;
	int pos = 0;
	
	for (iter i = std::begin(cont); i != std::end(cont); i++)
	{
		if (*i == num)
		{
			std::cout << "Found in position: " << pos << std::endl;
			return;
		}
		pos++;
	}
	std::cout << "Value not found." << std::endl;
}

#endif