/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:33:43 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/19 22:01:14 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(const Bureaucrat &other);
		
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &other);
		friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
		
		std::string &getName() const;
		int &getGrade() const;
		void upGrade();
		void downGrade();


	private:
		const std::string _name;
		int _grade;
};

#endif