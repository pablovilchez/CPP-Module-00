/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:46:30 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/07 00:54:24 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->_raw_bits = 0;
}

Fixed::Fixed(const Fixed& f)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int int_num)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_raw_bits = (int_num << Fixed::_c_bits);
}

Fixed::Fixed(const float float_num)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_raw_bits = roundf(float_num * (1 << Fixed::_c_bits));
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
	this->_raw_bits = raw;
}

int Fixed::toInt(void) const
{
	return (_raw_bits >> _c_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_raw_bits / (float)(1 << Fixed::_c_bits));
}

Fixed &Fixed::operator=(const Fixed &fix)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fix.getRawBits());
	return (*this);
}

bool Fixed::operator>(const Fixed &fix) const
{
	if (this->_raw_bits > fix.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &fix) const
{
	if (this->_raw_bits < fix.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &fix) const
{
	if (this->_raw_bits >= fix.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &fix) const
{
	if (this->_raw_bits <= fix.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &fix) const
{
	if (this->_raw_bits == fix.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &fix) const
{
	if (this->_raw_bits != fix.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &fix)
{
	return (Fixed(this->toFloat() + fix.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fix)
{
	return (Fixed(this->toFloat() - fix.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fix)
{
	
	return (Fixed(this->toFloat() * fix.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fix)
{
	return (Fixed(this->toFloat() / fix.toFloat()));
}

Fixed& Fixed::operator++(void)
{
	this->_raw_bits = this->_raw_bits + 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed aux(*this);
	this->_raw_bits++;
	return (aux);
}

Fixed& Fixed::operator--(void)
{
	this->_raw_bits = this->_raw_bits - 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed aux(*this);
	this->_raw_bits--;
	return (aux);
}

std::ostream &operator<<(std::ostream &str, Fixed const &fix)
{
	str << fix.toFloat();
	return (str);
}
