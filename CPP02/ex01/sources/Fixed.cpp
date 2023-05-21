/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:30:08 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/21 09:33:02 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->value = 0;
}

Fixed :: Fixed(const int num)
{
	std::cout << "Int constructor called." << std::endl;
	this->value = num << FRACTION_BITS;
}

Fixed :: Fixed(const float num)
{
	float tmp;

	tmp = num;
	std::cout << "Float constructor called." << std::endl;
	for (int i = 0; i < FRACTION_BITS; i++)
		tmp *= 2;
	this->value = tmp;
}

Fixed :: Fixed(const Fixed& num)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = num;
}

Fixed :: ~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed& Fixed :: operator=(const Fixed& right)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->value = right.getRawBits();
	return (*this);
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
	float tmp;
	
	tmp = this->value;
	for (int i = 0; i < FRACTION_BITS; i++)
		tmp /= 2;
	return (tmp);
}

int Fixed :: toInt(void) const
{
	float tmp;

	tmp = this->toFloat();
	return (roundf(tmp));
}

std::ostream& operator<<(std::ostream& out, const Fixed& right)
{
	out << right.toFloat();
	return (out);
}



