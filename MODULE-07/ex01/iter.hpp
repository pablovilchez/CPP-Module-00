/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:36:16 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/25 21:04:34 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP


template <typename T>
void iter(T *array, int len, T(*func)(T arg))
{
	for (int i = 0; i < len; i++)
		array[i] = func(array[i]);
}

#endif