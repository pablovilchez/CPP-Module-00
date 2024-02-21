/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:13:30 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/21 15:38:02 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name);
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &other);

		~Form();

		Form &operator=(const Form &other);

		const std::string &getName() const;
		const bool &getSigned() const;
		const int &getSignGrade() const;
		const int &getExecGrade() const;

		void beSigned(const Bureaucrat &brct);

		int validateRange(int grade);

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT {
					return "Error: Too high grade.";
				}
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT {
					return "Error: Too low grade.";
				}
		};

	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif