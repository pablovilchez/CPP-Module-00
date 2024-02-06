/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:51:35 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/06 10:16:13 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char **argv)
{
	std::string line;
	std::string aux;
	std::string src;
	std::string dst;
	unsigned int found_pos;

	if (argc != 4)
		return (std::cerr << "Error: number of arguments (3)" << std::endl, 1);
	if (!argv[2][0] || !argv[3][0])
		return (std::cerr << "Error: empty string" << std::endl, 1);
	std::ifstream read_file(argv[1]);
	if (!read_file.is_open())
		return (std::cerr << "Error opening file <" << argv[1] << ">" << std::endl,	1);
	std::string const name = std::string(argv[1]) + ".replace";
	std::ofstream write_file(name.c_str());
	if (!read_file.is_open())
	{
		std::cerr << "Error opening output file" << std::endl;
		read_file.close();
		return (1);
	}
	src = argv[2];
	dst = argv[3];
	while (getline(read_file, line))
	{
		while ((found_pos = line.find(src)) < line.length() && !(src == dst))
		{
			aux = line.substr(found_pos + src.length());
			line.erase(found_pos);
			line += dst + aux;
		}
		write_file << line;
		if (!read_file.eof())
			write_file << std::endl;
	}
	read_file.close();
	write_file.close();
	return (0);
}
