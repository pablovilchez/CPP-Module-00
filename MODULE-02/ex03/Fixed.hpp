/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:46:36 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/07 18:12:15 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& fix);
		Fixed(const int int_num);
		Fixed(const float float_num);

		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		int toInt(void) const;
		float toFloat(void) const;
		
		Fixed &operator=(const Fixed &fix);

		bool operator>(const Fixed &fix) const;
		bool operator<(const Fixed &fix) const;
		bool operator>=(const Fixed &fix) const;
		bool operator<=(const Fixed &fix) const;
		bool operator==(const Fixed &fix) const;
		bool operator!=(const Fixed &fix) const;
		
		Fixed operator+(const Fixed &fix);
		Fixed operator-(const Fixed &fix);
		Fixed operator*(const Fixed &fix);
		Fixed operator/(const Fixed &fix);

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed &fix1, Fixed &fix2);
		static const Fixed& min(const Fixed &fix1, const Fixed &fix2);
		static Fixed& max(Fixed &fix1, Fixed &fix2);
		static const Fixed &max(const Fixed &fix1, const Fixed &fix2);
		
	private:
		int _raw_bits;
		static const int _c_bits = 8;
};

std::ostream &operator<<(std::ostream &str, Fixed const &fix);

#endif
