/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:19:18 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/07 20:18:00 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& p) : _x(p._x), _y(p._y) {}

Point::~Point() {}

Point &Point::operator=(const Point& p)
{
	Point *ptr = new Point(p);
	return *ptr;
}

Fixed Point::getX() const 
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}