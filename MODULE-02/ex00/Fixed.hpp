/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:46:36 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/14 10:12:55 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& fix);

		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		Fixed &operator=(const Fixed& fix);
		
	private:
		int _raw_bits;
		static const int _fract = 8;
};


#endif
