/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:37:42 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/26 10:12:33 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern() { }

Intern::Intern(const Intern &other) { }
		
Intern::~Intern() { }

AForm * Intern::MakeForm(std::string formName, std::string target)
{
	std::string formList[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *formPtr = nullptr;
	int i = 0;
	
	while (i < 3 && formName != formList[i])
		i++;
	switch (i)
	{
		case 0:
			formPtr = new PresidentialPardonForm(target);
			break;
		case 1:
			formPtr = new RobotomyRequestForm(target);
			break;
		case 2:
			formPtr = new ShrubberyCreationForm(target);
			break;
		default:
			std::cerr << "Form name not found." << std::endl;
	}
	if (i < 4)
		std::cout << "Intern creates " << formName << std::endl;
	return formPtr;
}
		
Intern & Intern::operator=(const Intern &other)
{
	return *this;
}