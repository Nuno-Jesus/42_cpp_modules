/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:30:08 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/22 12:36:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->value = 0;
}

Fixed :: Fixed(Fixed& num)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = num;
}

Fixed :: ~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed& Fixed :: operator=(Fixed& right)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this == &right)
		return (*this);
	this->value = right.getRawBits();
	return (*this);
}
 
int Fixed :: getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->value);
}
 
void Fixed :: setRawBits(int const raw)
{
	this->value = raw;
}
