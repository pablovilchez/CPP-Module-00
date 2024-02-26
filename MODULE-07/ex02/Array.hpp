/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:06:05 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/26 12:10:36 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

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
		T *_tArray;
		unsigned int _tLen;

};

template <typename T>
Array<T>::Array() : _tArray(NULL), _tLen(0) { }

template <typename T>
Array<T>::Array(unsigned int n) : _tArray(new T[n]), _tLen(n) { }

template <typename T>
Array<T>::Array(const Array &other) : _tArray(new T[other._tLen]), _tLen(other._tLen)
{
	for (unsigned int i = 0; i < _tLen; i++)
		_tArray[i] = other._tArray[i];
}

template <typename T>
Array<T>::~Array()
{
	if (_tArray)
		delete[] _tArray;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (_tArray)
			delete[] _tArray;
		_tArray = new T[other._tLen];
		_tLen = other._tLen;
		for (unsigned int i = 0; i < _tLen; i++)
			_tArray[i] = other._tArray[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _tLen)
		throw std::out_of_range("Index out of range");
	return _tArray[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _tLen)
		throw std::out_of_range("Index out of range");
	return _tArray[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _tLen;
}



#endif