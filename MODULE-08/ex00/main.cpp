/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:33:31 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/27 17:18:29 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec = {0, 1, 2, 3, 4, 5};
	easyfind(vec, 3);

	std::vector<char> other = {'a', 'b', 'c', 'd', 'e'};
	easyfind(other, 'b');
	
	return 0;
}