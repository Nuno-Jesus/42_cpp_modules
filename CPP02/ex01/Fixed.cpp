/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:30:08 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/27 17:55:25 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed()
{
	std::cout << "Fixed default constructor called." << std::endl;
	this->value = 0;
}

Fixed :: Fixed(const int num)
{
	this->value = num * (1 << Fixed::BITS);
}

Fixed :: Fixed(const float num)
{
	this->value = num * (1 << Fixed::BITS);
}

Fixed :: Fixed(const Fixed& num)
{
	*this = num;
}

Fixed :: ~Fixed()
{
	std::cout << "Fixed destroyed." << std::endl;
}
 
int Fixed :: getRawBits(void) const
{
	return (this->value);
}
 
void Fixed :: setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed :: toFloat(void) const
{
	return ((float)this->value / (float)(1 << Fixed::BITS));
}

int Fixed :: toInt(void) const
{
	return (this->value >> Fixed::BITS);
}

Fixed& Fixed :: operator=(const Fixed& right)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this == &right)
		return (*this);
	this->value = right.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& right)
{
	out << right.toFloat();
	return (out);
}



