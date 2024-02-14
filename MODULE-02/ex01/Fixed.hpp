/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:46:36 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/14 12:19:24 by pvilchez         ###   ########.fr       */
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
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		int toInt(void) const;
		float toFloat(void) const;
		
		Fixed& operator=(const Fixed& f);

	private:
		int _raw_bits;
		static const int _fract = 8;
};

std::ostream &operator<<(std::ostream &str, const Fixed& fix);

#endif
