/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:14:26 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/21 16:17:23 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("unknown"), _signed(false), _signGrade(150), _execGrade(150) { }

Form::Form(std::string name) : _name(name), _signed(false), _signGrade(150), _execGrade(150) { }

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false),
		_signGrade(validateRange(signGrade)), _execGrade(validateRange(execGrade)) { }

Form::Form(const Form &other) : _name(other._name), _signed(other._signed),
		_signGrade(other._signGrade), _execGrade(other._execGrade) { }

Form::~Form() { }

Form & Form::operator=(const Form &other)
{
	_signed = other._signed;
	return *this;
}

const std::string & Form::getName() const
{
	return _name;
}

const bool & Form::getSigned() const
{
	return _signed;
}

const int & Form::getSignGrade() const
{
	return _signGrade;
}

const int & Form::getExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &brct)
{
	try
	{
		if (brct.getGrade() > _signGrade)
			throw GradeTooLowException();
		_signed = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

int Form::validateRange(int grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return grade;
}


std::ostream& operator<<(std::ostream &out, const Form &f)
{
	return std::cout << "Form name: " << f.getName() << "  Sign: " << f.getSignGrade() <<
		"  Execute: " << f.getExecGrade() << "  Signed: " << f.getSigned() << std::endl;
}
	