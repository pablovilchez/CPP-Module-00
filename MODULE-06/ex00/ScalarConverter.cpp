/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:43:09 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/26 09:21:42 by pvilchez         ###   ########.fr       */
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
	int casting = 0;

	try
	{
		// printable char:
		if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
		{
			std::cout << "char: " << input << std::endl;
			std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(input[0]) << std::endl;
			std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
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
		if (input[input.length() - 1] == 'f')
		{
			floatCast = std::stof(input);
			doubleCast = static_cast<double>(floatCast);
			intCast = static_cast<int>(doubleCast);
			if (intCast >= 32 && intCast <= 126)
				charCast = static_cast<char>(intCast);
			else
				charCast = "Non displayable";
			std::cout << "char: " << charCast << std::endl;
			std::cout << "int: " << intCast << std::endl;
			std::cout << "float: " << floatCast;
			if (floatCast == intCast)
				std::cout << ".0";
			std::cout << "f" << std::endl;
			std::cout << "double: " << doubleCast;
			if (doubleCast == intCast)
				std::cout << ".0";
			std::cout << std::endl;
			return;
		}

		// double case:
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '.')
			{
				doubleCast = std::stod(input);
				intCast = static_cast<int>(doubleCast);
				floatCast = static_cast<float>(doubleCast);
				if (intCast >= 32 && intCast <= 126)
					charCast = static_cast<char>(intCast);
				else
					charCast = "Non displayable";
				std::cout << "char: " << charCast << std::endl;
				std::cout << "int: " << intCast << std::endl;
				std::cout << "float: " << floatCast;
				if (floatCast == intCast)
					std::cout << ".0";
				std::cout << "f" << std::endl;
				std::cout << "double: " << doubleCast;
				if (doubleCast == intCast)
					std::cout << ".0";
				std::cout << std::endl;
				return;
			}
		}

		// int case:
		intCast = std::stoi(input);
		doubleCast = static_cast<double>(intCast);
		floatCast = static_cast<float>(intCast);
		if (intCast >= 32 && intCast <= 126)
			charCast = static_cast<char>(intCast);
		else
			charCast = "Non displayable";
		std::cout << "char: " << charCast << std::endl;
		std::cout << "int: " << intCast << std::endl;
		std::cout << "float: " << floatCast;
		if (floatCast == intCast)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: " << doubleCast;
		if (doubleCast == intCast)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
