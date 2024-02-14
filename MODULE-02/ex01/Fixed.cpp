/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:46:30 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/14 12:17:35 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fix) : _raw_bits(fix._raw_bits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int int_num)
{
	std::cout << "Int constructor called" << std::endl;
	_raw_bits = (int_num << _fract);
}

Fixed::Fixed(const float float_num)
{
	std::cout << "Float constructor called" << std::endl;
	_raw_bits = roundf(float_num * (1 << _fract));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_raw_bits = f._raw_bits;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_raw_bits);
}

void Fixed::setRawBits(int const raw)
{
	_raw_bits = raw;
}

int Fixed::toInt(void) const
{
	return (_raw_bits >> _fract);
}

float Fixed::toFloat(void) const
{
	return ((float)_raw_bits / (float)(1 << _fract));
}

std::ostream &operator<<(std::ostream &str, const Fixed &fix)
{
	str << fix.toFloat();
	return (str);
}
