/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:29:08 by marvin            #+#    #+#             */
/*   Updated: 2023/05/21 22:29:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point :: Point() : x(0), y(0)
{
	// std::cout << "Default constructor called." << std::endl;
}

Point :: Point(const float x, const float y) : x(x), y(y)
{
	// std::cout << "Parameter constructor called." << std::endl;
}

Point::Point( const Point &p ) : x(p.x), y(p.y) 
{
    // std::cout << "Point created" << std::endl;
}

Point :: ~Point()
{
	// std::cout << "Point (" << this->x << ", " << this->y << ") deleted." << std::endl; 
}

Point& Point :: operator=(const Point& p)
{
	if (this == &p)
		return (*this);
	(Fixed)this->x = p.getX();
	(Fixed)this->y = p.getY();
	return (*this);
}

bool Point :: operator==(const Point& p)
{
	return((Fixed)this->x == p.getX() && (Fixed)this->y == p.getY());
}

Fixed Point :: getX() const
{
	return (Fixed(this->x));
}

Fixed Point :: getY() const
{
	return (Fixed(this->y));
}
