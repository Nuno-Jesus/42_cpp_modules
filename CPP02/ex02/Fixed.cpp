/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:30:08 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/29 18:47:26 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed()
{
	// std::cout << "Default constructor called." << std::endl;
	this->value = 0;
}

Fixed :: Fixed(const int num)
{
	this->value = num << Fixed::BITS;
}

Fixed :: Fixed(const float num)
{
	this->value = (num * (1 << Fixed::BITS));
}

Fixed :: Fixed(const Fixed& num)
{
	// std::cout << "Copy constructor called." << std::endl;
	*this = num;
}

Fixed :: ~Fixed()
{
	// std::cout << "Destructor called." << std::endl;
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

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\ OPERATORS /=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

Fixed& Fixed :: operator=(const Fixed& right)
{	
	// std::cout << "Copy assignment operator called." << std::endl;
	if (this == &right)
		return (*this);
	this->value = right.getRawBits();
	return (*this);
}

bool Fixed :: operator>(const Fixed& right)
{
	return (this->value > right.value);
}

bool Fixed :: operator<(const Fixed& right)
{
	return (this->value < right.value);
}

bool Fixed :: operator>=(const Fixed& right)
{
	return (this->value >= right.value);
}

bool Fixed :: operator<=(const Fixed& right)
{
	return (this->value <= right.value);
}

bool Fixed :: operator==(const Fixed& right)
{
	return (this->value == right.value);
}

bool Fixed :: operator!=(const Fixed& right)
{
	return (this->value != right.value);
}

Fixed Fixed :: operator+(const Fixed& right)
{
	return Fixed(this->value + right.value);
}

Fixed Fixed :: operator-(const Fixed& right)
{
	return Fixed(this->value - right.value);
}

Fixed Fixed :: operator*(const Fixed& right)
{
	return Fixed(this->value * right.value);
}

Fixed Fixed :: operator/(const Fixed& right)
{
	return Fixed(this->value / right.value);
}

Fixed Fixed :: operator++(void)
{	
	this->value++;
	return (*this);
}

Fixed Fixed :: operator--(void)
{
	this->value--;
	return (*this);
}

Fixed Fixed :: operator++(int dummy)
{
	Fixed clone(*this);

	(void) dummy;
	++(*this);
	return (clone);
}

Fixed Fixed :: operator--(int dummy)
{
	Fixed clone(*this);

	(void) dummy;
	--(*this);
	return (clone);	
}

std::ostream& operator<<(std::ostream& out, const Fixed& right)
{
	out << right.toFloat();
	return (out);
}

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\ MIN AND MAX /=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_


Fixed& Fixed :: min(Fixed& f1, Fixed& f2)
{	
	return (f1 < f2 ? f1 : f2); 
}

const Fixed& Fixed :: min(const Fixed& f1, const Fixed& f2)
{
	return (f1.toFloat() < f2.toFloat() ? f1 : f2); 
}

Fixed& Fixed :: max(Fixed& f1, Fixed& f2)
{
	return (f1 > f2 ? f1 : f2); 
}

const Fixed& Fixed :: max(const Fixed& f1, const Fixed& f2)
{
	return (f1.toFloat() > f2.toFloat() ? f1 : f2); 
}



