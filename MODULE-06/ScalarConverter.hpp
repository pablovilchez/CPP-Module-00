/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:20:47 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/24 00:42:51 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void convert(const std::string &str);
		void printValues(std::string checkStr);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter & other);
		ScalarConverter &operator=(ScalarConverter &other);
		
};


#endif