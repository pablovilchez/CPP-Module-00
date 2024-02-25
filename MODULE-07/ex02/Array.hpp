/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:06:05 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/25 21:59:06 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include "Array.tpp"

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);

		~Array();

		Array &operator=(const Array &other);
		T &operator[](unsigned int pos);
		const T &operator[](unsigned int pos) const;
		
		unsigned int size() const;

	private:
		T *tArray;
		unsigned int tLen;

};


#endif