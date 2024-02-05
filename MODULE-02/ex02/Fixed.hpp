/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:46:36 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/05 00:25:17 by pvilchez         ###   ########.fr       */
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
		Fixed(const Fixed& f);
		Fixed(const int int_num);
		Fixed(const float float_num);
		~Fixed();
		Fixed &operator=(const Fixed &f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
		
	private:
		int _fix_num;
		static const int _c_bits = 8;
};

std::ostream &operator<<(std::ostream &str, Fixed const &fix);

#endif
