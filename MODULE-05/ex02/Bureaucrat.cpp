/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:33:18 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/23 17:57:25 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) { }

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) { }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		if (grade < 1)
		{
			_grade = 150;
			throw GradeTooHighException();
		}
		else if (grade > 150)
		{
			_grade = 150;
			throw GradeTooLowException();
		}
		_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) { }
		
Bureaucrat::~Bureaucrat() { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	_grade = other._grade;
	return *this;
}

const std::string & Bureaucrat::getName() const
{
	return _name;
}

const int & Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::upGrade()
{
	try
	{
		if (_grade == 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::downGrade()
{
	try
	{
		if (_grade == 150)
			throw GradeTooLowException();
		_grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm & form)
{
	if (_grade <= form.getSignGrade() && form.getSigned())
	{
		std::cout << _name << " couldn't sign " << form.getName();
		std::cout << " because is already signed." << std::endl;
	}
	else
	{
		form.beSigned(*this);
		if (_grade <= form.getSignGrade())
			std::cout << _name << " signed " << form.getName() << std::endl;
		else
		{
			std::cout << _name << " couldn't sign " << form.getName();
			std::cout << " because it needs an upper grade." << "  (Actual grade: ";
			std::cout << _grade << "   Required: " << form.getSignGrade() << ")" << std::endl;
		}
	}
}

void Bureaucrat::executeForm(const AForm & form) const
{
	if (!form.getSigned())
		std::cout << "The form has not been signed yet" << std::endl;
	else
	{
		try
		{
			if (_grade > form.getExecGrade())
				throw GradeTooLowException();
			form.execute(*this);
			std::cout << getName() << " executed " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " " << getName() << " doesn't have permission." << std::endl;
		}
	}
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
	return std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
}
	