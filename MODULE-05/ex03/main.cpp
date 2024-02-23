/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:51:23 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/23 18:11:00 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Bureaucrat bur_a("Presi", 1);
	Bureaucrat bur_b("Encargado", 35);
	Bureaucrat bur_c("Pringaillo", 90);
	Bureaucrat bur_d("Last monkey", 150);

	Intern randomIntern;

	AForm *formul;
	
	std::cout << std::endl;
	formul = randomIntern.MakeForm("robotomy request", "Manolito");
	bur_a.signForm(*formul);
	std::cout << "Execute Robotomy tests:" << std::endl;
	formul->execute(bur_c);  // Fail (has 90 - required 45)
	formul->execute(bur_b);  // OK (has 35 - required 45)
	delete formul;
	
	std::cout << std::endl;
	formul = randomIntern.MakeForm("presidential pardon", "Pepito");
	bur_a.signForm(*formul);
	std::cout << "Execute Presidential tests:" << std::endl;
	bur_d.executeForm(*formul);  // Fail (has 150 - required 5)
	bur_a.executeForm(*formul);  // OK (has 1 - required 5)
	delete formul;

	std::cout << std::endl;
	formul = randomIntern.MakeForm("shrubbery creation", "Garden");
	bur_a.signForm(*formul);
	std::cout << "Execute Shrubbery tests:" << std::endl;
	formul->execute(bur_d);  // Fail (has 150 - required 137)
	formul->execute(bur_c);  // OK (has 90 - required 137)
	delete formul;

	std::cout << std::endl;
	formul = randomIntern.MakeForm("incorrect name", "limbo");
	bur_a.signForm(*formul);
	std::cout << "Incorrect tests:" << std::endl;
	bur_c.executeForm(*formul);  // Fail (has 90 - required 45)
	bur_a.executeForm(*formul);  // OK (has 1 - required 5)

}