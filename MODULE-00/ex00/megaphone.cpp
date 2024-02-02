/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:32:59 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/03 23:33:02 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
