/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:51:23 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/22 12:26:37 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat bur_a("Pepe");
	std::cout << std::endl << bur_a << std::endl;
	
	Bureaucrat bur_b("Paco", 10);
	std::cout << std::endl << bur_b << std::endl;

	Form form_a("Poco seguro", 150, 150);
	std::cout << std::endl << form_a << std::endl;
	bur_a.signForm(form_a);
	bur_b.signForm(form_a);
	std::cout << std::endl;

	Form form_b("Medio seguro", 90, 90);
	std::cout << std::endl << form_b << std::endl;
	bur_a.signForm(form_b);
	bur_b.signForm(form_b);
	std::cout << std::endl;

	Form form_c("Muy seguro", 1, 1);
	std::cout << std::endl << form_c << std::endl;
	bur_a.signForm(form_c);
	bur_b.signForm(form_c);
	std::cout << std::endl;
}