/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:45:19 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/04 12:45:15 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	
	if (argc == 2)
		harl.complain(argv[1]);
	else
	{
		std::cerr << "Error: incorrect num of arguments (1)" << std::endl << std::endl;
		return (1);
	}
	return (0);
}
