/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:51:23 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/22 17:30:48 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat bur_a("Presi", 1);
	Bureaucrat bur_b("Encargado", 35);
	Bureaucrat bur_c("Pringaillo", 90);
	Bureaucrat bur_d("Last monkey", 150);

	AForm *for_a = new RobotomyRequestForm("Manolito");
	AForm *for_b = new PresidentialPardonForm("Pepito");
	AForm *for_c = new ShrubberyCreationForm("garden");
	
	std::cout << std::endl << "Execute Robotomy tests:" << std::endl;
	for_a->execute(bur_c);  // Fail (has 90 - required 45)
	for_a->execute(bur_b);  // OK (has 35 - required 45)
	
	std::cout << std::endl << "Execute Presidential tests:" << std::endl;
	for_b->execute(bur_d);  // Fail (has 150 - required 5)
	for_b->execute(bur_a);  // OK (has 1 - required 5)

	std::cout << std::endl << "Execute Shrubbery tests:" << std::endl;
	for_c->execute(bur_d);  // Fail (has 150 - required 137)
	for_c->execute(bur_c);  // OK (has 90 - required 137)

	std::cout << std::endl << "ExecuteForm tests:" << std::endl;
	bur_c.executeForm(*for_a);  // Fail (has 90 - required 45)
	bur_a.executeForm(*for_b);  // OK (has 1 - required 5)

	delete for_a;
	delete for_b;
	delete for_c;
}