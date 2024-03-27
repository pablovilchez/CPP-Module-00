/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:33:31 by pvilchez          #+#    #+#             */
/*   Updated: 2024/03/27 10:54:49 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(7);
	vec.push_back(3);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(8);
	easyfind(vec, 3);

	std::vector<char> other;
	other.push_back('a');
	other.push_back('b');
	other.push_back('c');
	other.push_back('d');
	other.push_back('e');
	easyfind(other, 'e');
	
	return 0;
}