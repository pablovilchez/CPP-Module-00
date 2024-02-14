/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:46:30 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/14 12:04:36 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _raw_bits(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) : _raw_bits(f._raw_bits)
{
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int int_num)
{
	//std::cout << "Int constructor called" << std::endl;
	_raw_bits = (int_num << _fract);
}

Fixed::Fixed(const float float_num)
{
	//std::cout << "Float constructor called" << std::endl;
	_raw_bits = roundf(float_num * (1 << _fract));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
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

Fixed &Fixed::operator=(const Fixed &fix)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	_raw_bits = fix._raw_bits;
	return (*this);
}

bool Fixed::operator>(const Fixed &fix) const
{
	if (_raw_bits > fix._raw_bits)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &fix) const
{
	if (_raw_bits < fix._raw_bits)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &fix) const
{
	if (_raw_bits >= fix._raw_bits)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &fix) const
{
	if (_raw_bits <= fix._raw_bits)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &fix) const
{
	if (_raw_bits == fix._raw_bits)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &fix) const
{
	if (_raw_bits != fix._raw_bits)
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &fix)
{
	return (Fixed(toFloat() + fix.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fix)
{
	return (Fixed(toFloat() - fix.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fix)
{
	
	return (Fixed(toFloat() * fix.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fix)
{
	return (Fixed(toFloat() / fix.toFloat()));
}

Fixed& Fixed::operator++(void)
{
	_raw_bits = _raw_bits + 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed aux(*this);
	_raw_bits = _raw_bits + 1;
	return (aux);
}

Fixed& Fixed::operator--(void)
{
	_raw_bits = _raw_bits - 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed aux(*this);
	_raw_bits = _raw_bits - 1;
	return (aux);
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1._raw_bits < fix2._raw_bits)
		return (fix1);
	else
		return (fix2);
}

const Fixed& Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1._raw_bits < fix2._raw_bits)
		return (fix1);
	else
		return (fix2);
}

Fixed& Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1._raw_bits > fix2._raw_bits)
		return (fix1);
	else
		return (fix2);
}

const Fixed& Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1._raw_bits > fix2._raw_bits)
		return (fix1);
	else
		return (fix2);
}

std::ostream &operator<<(std::ostream &str, Fixed const &fix)
{
	str << fix.toFloat();
	return (str);
}
