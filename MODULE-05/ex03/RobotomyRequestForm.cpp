/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:57:31 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/23 18:05:56 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
		AForm("RobotomyRequestForm", "undetermined", 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
		AForm(other) { }

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
		AForm("RobotomyRequestForm", target, 72, 45) { }
		
RobotomyRequestForm::~RobotomyRequestForm() { }

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
		std::cout << "The form has not been signed yet" << std::endl;
	else
	{
		try
		{
			if (executor.getGrade() > getExecGrade())
				throw AForm::GradeTooLowException();
			std::cout << "<whirr, whirr, whirr!!...>" << std::endl;
			std::cout << getTarget();
			std::cout << " has been robotomized successfully 50% of the time." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl << "Robotomy failed." << std::endl;
		}
	}
}
