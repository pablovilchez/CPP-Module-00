/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:33:43 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/22 16:22:45 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &other);
		
		const std::string &getName() const;
		const int &getGrade() const;
		void upGrade();
		void downGrade();
		void signForm(Form &form);
		
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
		int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif