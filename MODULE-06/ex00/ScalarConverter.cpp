/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:43:09 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/28 12:34:41 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(ScalarConverter & other)
{ *this = other; }

ScalarConverter& ScalarConverter::operator=(ScalarConverter &other)
{ return *this; }

ScalarConverter::~ScalarConverter() { }

void ScalarConverter::convert(const std::string &input)
{
	std::string charCast;
	int intCast;
	float floatCast;
	double doubleCast;
	char *endptr;

	try
	{
		// printable char:
		if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
		{
			std::cout << "char: " << "'" << input << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
			return;
		}

		// special cases:
		std::string special[6] = {"-inf", "+inf", "nan", "-inff", "+inff", "nanf"};
		for (int i = 0; i < 6; i++)
		{
			if (input == special[i])
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << special[i%3] << "f" << std::endl;
				std::cout << "double: " << special[i%3] << std::endl;
				return;
			}	
		}
		
		// float case:
		floatCast = std::strtof(input.c_str(), &endptr);
		if (endptr != input && *endptr == 'f')
		{
			std::cout << " *Detected: float*" << std::endl;
			if (floatCast >= 32 && floatCast <= 126)
				std::cout << "char: " << "'" << static_cast<char>(floatCast) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			intCast = static_cast<int>(floatCast);
			std::cout << "int: " << intCast << std::endl;
			std::cout << "float: " << floatCast << (floatCast == intCast ? ".0f" : "f") << std::endl;
			doubleCast = static_cast<double>(floatCast);
			std::cout << "double: " << doubleCast << (doubleCast == intCast ? ".0" : "") << std::endl;
			return;
		}

		// double case:
		doubleCast = std::strtod(input.c_str(), &endptr);
		if (endptr != input && doubleCast != static_cast<int>(doubleCast))
		{
			std::cout << " *Detected: double*" << std::endl;
			if (doubleCast >= 32 && doubleCast <= 126)
				std::cout << "char: " << "'" << static_cast<char>(doubleCast) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			intCast = static_cast<int>(doubleCast);
			std::cout << "int: " << intCast << std::endl;
			floatCast = static_cast<float>(doubleCast);
			std::cout << "float: " << floatCast << (floatCast == intCast ? ".0f" : "f") << std::endl;
			std::cout << "double: " << doubleCast << (doubleCast == intCast ? ".0" : "") << std::endl;
			return;
		}

		// int case:
		intCast = std::strtol(input.c_str(), &endptr, 10);
		if (endptr != input)
		{
			std::cout << " *Detected: integer*" << std::endl;
			if (intCast >= 32 && intCast <= 126)
				std::cout << "char: " << "'" << static_cast<char>(intCast) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << intCast << std::endl;
			floatCast = static_cast<float>(intCast);
			std::cout << "float: " << floatCast << ".0f" << std::endl;
			doubleCast = static_cast<double>(intCast);
			std::cout << "double: " << doubleCast << ".0" << std::endl;
			return;
		}
		std::cerr << "Error: bad argument" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
