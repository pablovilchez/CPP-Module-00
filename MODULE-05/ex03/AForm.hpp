/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:13:30 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/22 16:38:25 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(std::string name, std::string _target, int signGrade, int execGrade);
		AForm(const AForm &other);

		~AForm();

		AForm &operator=(const AForm &other);

		const std::string &getName() const;
		const bool &getSigned() const;
		const int &getSignGrade() const;
		const int &getExecGrade() const;
		const std::string &getTarget() const;

		void beSigned(const Bureaucrat &brct);
		virtual void execute(const Bureaucrat &executor) const = 0;

		int validateRange(int grade);

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw() {
					return "Error: Too high grade.";
				}
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw() {
					return "Error: Too low grade.";
				}
		};

	private:
		const std::string _name;
		const std::string _target;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif