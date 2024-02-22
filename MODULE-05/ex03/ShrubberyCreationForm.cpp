/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:57:13 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/22 19:46:50 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
		AForm("ShrubberyCreationForm", "undetermined", 145, 137) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
		AForm(other) { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
		AForm("ShrubberyCreationForm", target, 145, 137) { }
		
ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (&executor == nullptr)
	{
		std::cerr << "Error: Null pointer received." << std::endl;
        return;
	}
	try
	{
		if (executor.getGrade() > getExecGrade())
			throw AForm::GradeTooLowException();
		std::ofstream file(getTarget() + "_shrubbery", std::ios::trunc);
		if (file.is_open())
		{
			file << "         &&& &&  & &&                     &&& &&  & &&            \n";
			file << "      && &\\/&\\|& ()|/ @, &&            && &\\/&\\|& ()|/ @, &&      \n";
			file << "      &\\/(/&/&||/& /_/)_&/_&           &\\/(/&/&||/& /_/)_&/_&     \n";
			file << "   &() &\\/&|()|/&\\/ '%' & ()        &() &\\/&|()|/&\\/ '%' & ()     \n";
			file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&      &_\\_&&_\\ |& |&&/&__%_/_& &&    \n";
			file << " &&   && & &| &| /& & % ()& /&&   &&   && & &| &| /& & % ()& /&&  \n";
			file << " ()&_---()&\\&\\|&&-&&--%---()~     ()&_---()&\\&\\|&&-&&--%---()~    \n";
			file << "     &&     \\|||                      &&     \\|||                 \n";
			file << "             |||                              |||                 \n";
			file << "             |||                              |||                 \n";
			file << "             |||                              |||                 \n";
			file << "       , -=-~  .-^- _                   , -=-~  .-^- _            \n";
        	file.close();
		}
		else
			std::cerr << "Error opening file." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
