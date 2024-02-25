/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:43:48 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/25 15:15:10 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

struct Data
{
	int rawPtr;

	Data() : rawPtr(42) { }

	Data(int raw) : rawPtr(raw) { }
	
	~Data() { }
	
	Data(Data const &other) { *this = other; }
	
	Data &operator=(Data const &other)
	{
		if (this != &other)
			rawPtr = other.rawPtr;
		return *this;
	}
};

#endif