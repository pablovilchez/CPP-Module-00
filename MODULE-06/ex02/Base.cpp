/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:38:43 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/25 19:52:59 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base::~Base() { }

Base *generate()
{
	std::srand(std::time(0));
	
	int i = std::rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Casted A by a pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Casted B by a pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Casted C by a pointer" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Casted A by a reference" << std::endl;
	}
	catch(const std::exception &e)
	{ }
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Casted B by a reference" << std::endl;
	}
	catch(const std::exception &e)
	{ }
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Casted C by a reference" << std::endl;
	}
	catch(const std::exception &e)
	{ }
}