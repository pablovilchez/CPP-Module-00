/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:51:35 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/03 20:18:26 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrect number of arguments (3)" << std::endl;
		return (1);
	}
	std::ifstream r_fich(argv[1]);
	if (!r_fich.is_open())
	{
		std::cerr << "Error opening file <" << argv[1] << ">" << std::endl;
		return (1);
	}
	std::string const name = std::string(argv[1]) + ".replace";
	std::ofstream w_fich(name.c_str());
	if (!r_fich.is_open())
	{
		std::cerr << "Error opening output file" << std::endl;
		r_fich.close();
		return (1);
	}
	std::cout << "Success opening files" << std::endl;	
	return (0);
}
