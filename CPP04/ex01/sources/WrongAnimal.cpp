/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:11:25 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 03:11:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	LOG("WrongAnimal default constructor called.");
}

WrongAnimal::WrongAnimal(const WrongAnimal& wa)
{
	LOG("WrongAnimal copy constructor called.");
	this->type = wa.type;
}

WrongAnimal::~WrongAnimal(void)
{
	LOG("WrongAnimal died.");
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& right)
{
	LOG("WrongAnimal assignment operator called.");
	if (this == &right)
		return (*this);
	this->type = right.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal: ..." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);	
}

void WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}
