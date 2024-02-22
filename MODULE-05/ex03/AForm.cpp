/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:14:26 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/22 19:49:17 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("unknown"), _signed(false), _signGrade(150), _execGrade(150),
		_target("undetermined") { }

AForm::AForm(std::string name) : _name(name), _signed(false), _signGrade(150),
		_execGrade(150), _target("undetermined") { }

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false),
		_signGrade(validateRange(signGrade)), _execGrade(validateRange(execGrade)),
		_target("undetermined") { }

AForm::AForm(std::string name, std::string target, int signGrade, int execGrade) :
		_name(name), _signed(false), _signGrade(validateRange(signGrade)),
		_execGrade(validateRange(execGrade)), _target(target) { }

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed),
		_signGrade(other._signGrade), _execGrade(other._execGrade),
		_target(other._target) { }

AForm::~AForm() { }

AForm & AForm::operator=(const AForm &other)
{
	_signed = other._signed;
	return *this;
}

const std::string & AForm::getName() const
{
	return _name;
}

const bool & AForm::getSigned() const
{
	return _signed;
}

const int & AForm::getSignGrade() const
{
	return _signGrade;
}

const int & AForm::getExecGrade() const
{
	return _execGrade;
}

const std::string & AForm::getTarget() const
{
	return _target;
}

void AForm::beSigned(const Bureaucrat &brct)
{
	if (&brct == nullptr)
	{
		std::cerr << "Error: Null pointer received." << std::endl;
        return;
	}
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

int AForm::validateRange(int grade)
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

std::ostream& operator<<(std::ostream &out, const AForm &f)
{
	if (&out == nullptr || &f == nullptr)
		return std::cerr << "Error: Null pointer received." << std::endl;
	return std::cout << "Form name: " << f.getName() << "  Sign: " << f.getSignGrade() <<
		"  Execute: " << f.getExecGrade() << "  Signed: " << f.getSigned() << std::endl;
}
	