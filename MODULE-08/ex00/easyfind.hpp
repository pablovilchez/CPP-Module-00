/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:33:35 by pvilchez          #+#    #+#             */
/*   Updated: 2024/03/27 12:11:54 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>

template<typename T>
void easyfind(const T &cont, int num)
{
	typename T::const_iterator it;

	it = std::find(cont.begin(), cont.end(), num);
	if (it != cont.end())
		std::cout << "Found in position: " << std::distance(cont.begin(), it) << std::endl;
	else
		std::cout << "Value not found." << std::endl;
}

#endif