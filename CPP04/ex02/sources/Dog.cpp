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
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	LOG("Dog copy constructor called.");
	this->brain = NULL;
	*this = dog;
}

Dog::~Dog(void)
{
	LOG("Dog died.");
	delete this->brain;
}

Dog& Dog::operator=(const Dog& right)
{
	LOG("Dog assigment operator called.");
	if (this == &right)
		return (*this);
	delete this->brain;
	this->brain = new Brain(*right.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog: BARK!!!" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}
