/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:51:23 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/22 12:28:10 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat a;
	std::cout << std::endl << "--- Default Const ---" << std::endl << a << std::endl;
	a.downGrade();
	
	Bureaucrat b("Pepe");
	std::cout << std::endl << "--- 1 argument Const ---" << std::endl << b << std::endl;
	
	Bureaucrat c("Paco", 1);
	std::cout << std::endl << "--- 2 arguments (max) Const ---" << std::endl << c << std::endl;
	c.upGrade();

	Bureaucrat d("Princeso", 150);
	std::cout << std::endl << "--- 2 arguments (min) Const ---" << std::endl << d << std::endl;
	d.downGrade();

	Bureaucrat e(d);
	std::cout << std::endl << "--- Copy Const ---" << std::endl << e << std::endl;
}