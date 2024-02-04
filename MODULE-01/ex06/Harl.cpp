/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:45:46 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/04 17:44:38 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	
}

Harl::~Harl()
{
	
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-";
	std::cout << "pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t";
	std::cout << " put enough bacon in my burger! If you did, I wouldn’t be asking ";
	std::cout << "for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been ";
	std::cout << "coming for years whereas you started working here since last";
	std::cout << " month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	h_func methods[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	
	while (i < 4)
	{
		if (level == levels[i])
			break;
		i++;
	}
	do
	{
		switch (i)
		{
			case 0:
				(this->*methods[0])();
				break;
			case 1:
				(this->*methods[1])();
				break;
			case 2:
				(this->*methods[2])();
				break;
			case 3:
				(this->*methods[3])();
				break;
			default:
				std::cout << "Error: complain level not found." << std::endl;
		}
		std::cout << std::endl;
		i++;
	} while (i < 4);
}
