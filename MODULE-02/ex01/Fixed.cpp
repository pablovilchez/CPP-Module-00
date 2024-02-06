/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:46:30 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/05 00:33:13 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fix_num = 0;
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int int_num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fix_num = (int_num << Fixed::_c_bits);
}

Fixed::Fixed(const float float_num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fix_num = roundf(float_num * (1 << Fixed::_c_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(f.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fix_num);
}

void Fixed::setRawBits(int const raw)
{
	this->_fix_num = raw;
}

int Fixed::toInt(void) const
{
	return (_fix_num >> _c_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fix_num / (float)(1 << Fixed::_c_bits));
}

std::ostream &operator<<(std::ostream &str, Fixed const &fix)
{
	str << fix.toFloat();
	return (str);
}
