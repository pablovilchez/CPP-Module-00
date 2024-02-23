/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:43:09 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/23 12:36:02 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(ScalarConverter & other) { }

ScalarConverter& ScalarConverter::operator=(ScalarConverter &other)
{ return *this; }

ScalarConverter::~ScalarConverter() { }

void ScalarConverter::convert(const std::string &str)
{
	std::string charCast;
	int intCast;
	float floatCast;
	double doubleCast;

	// Check a character case:
	if (str.length() == 1 && isprint(str[0]) && !isnumber(str[0]))
	{
		charCast = str;
		intCast = static_cast<int>(str[0]);
		floatCast = static_cast<float>(str[0]);
		doubleCast = static_cast<double>(str[0]);
	}
	std::cout << "char: " << charCast << std::endl;
	std::cout << "int: " << intCast << std::endl;
	std::cout << "float: " << floatCast << std::endl;
	std::cout << "double: " << doubleCast << std::endl;
	
}
