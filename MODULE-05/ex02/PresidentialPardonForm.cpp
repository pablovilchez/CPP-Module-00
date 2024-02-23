/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:53:10 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/23 18:01:09 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
		AForm("PresidentialPardonForm", "undetermined", 25, 5) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
		AForm(other) { }

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
		AForm("PresidentialPardonForm", target, 25, 5) { }
		
PresidentialPardonForm::~PresidentialPardonForm() { }

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
		std::cout << "The form has not been signed yet" << std::endl;
	else
	{
		try
		{
			if (executor.getGrade() > getExecGrade())
				throw AForm::GradeTooLowException();
			std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.";
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
