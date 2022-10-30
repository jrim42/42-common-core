/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:25:31 by jrim              #+#    #+#             */
/*   Updated: 2022/08/22 12:00:47 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	check_position(Point const p1, Point const p2, Point const q1, Point const q2);
Fixed	get_slope(Point const p1, Point const p2);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// m(x - x1) - (y - y1) = 0
	// mx - y + (-m * x1 + y1) = 0
	if (check_position(a, b, c, point) == false)
		return (false);
	if (check_position(b, c, a, point) == false)
		return (false);
	if (check_position(c, a, b, point) == false)
		return (false);
	return (true);
}

bool	check_position(Point const p1, Point const p2, Point const q1, Point const q2)
{
	Fixed	m;
	Fixed	n;

	if (p1.get_x() - p2.get_x() == 0)
	{
		if ((q1.get_x() - p1.get_x()) * (q2.get_x() - p1.get_x()) <= 0)
			return (false);
	}
	else
	{
		m = get_slope(p1, p2);
		n = (m * -1 * p1.get_x()) + p1.get_y();
		if ((m * q1.get_x() - q1.get_y() + n) * (m * q2.get_x() - q2.get_y() + n) <= 0)
			return (false);
	}
	return (true);
}

Fixed	get_slope(Point const p1, Point const p2)
{
	Fixed	denom;
	Fixed	numer;

	denom = p2.get_x() - p1.get_x();
	numer = p2.get_y() - p1.get_y();
	if (numer == 0)
		return (0);
	else 
		return (numer / denom);
}