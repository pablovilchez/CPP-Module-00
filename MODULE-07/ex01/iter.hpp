/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:36:16 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/26 18:27:27 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP


template <typename T>
void iter(T *array, int len, T(*func)(const T &arg))
{
	for (int i = 0; i < len; i++)
		array[i] = func(array[i]);
}

template <typename T>
void iter(T *array, int len, void(*func)(const T &arg))
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}

#endif