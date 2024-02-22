/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:20:47 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/22 22:04:42 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void convert(const std::string &str);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter & other);
		ScalarConverter &operator=(ScalarConverter &other);
		
};

#endif