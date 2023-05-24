/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:48:37 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 02:48:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	LOG("Dog default constructor called.");
	this->type = "Dog";
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	LOG("Dog copy constructor called.");
}

Dog::~Dog(void)
{
	LOG("Dog died.");
}

Dog& Dog::operator=(const Dog& dog)
{
	LOG("Dog assigment operator called.");
	if (this == &dog)
		return (*this);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog: BARK!!!" << std::endl;
}
