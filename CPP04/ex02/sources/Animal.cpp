/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:39:08 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 02:39:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	LOG("Animal default constructor called.");
}

Animal::Animal(const Animal& animal)
{
	LOG("Animal copy constructor called.");
	this->type = animal.type;
}

Animal::~Animal(void)
{
	LOG("Animal died.");
}

Animal& Animal::operator=(const Animal& right)
{
	LOG("Animal assignment operator called.");
	if (this == &right)
		return (*this);
	this->type = right.type;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->type);	
}

void Animal::setType(const std::string& type)
{
	this->type = type;
}
