/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:48:37 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 02:48:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	LOG("Cat default constructor called.");
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	LOG("Cat copy constructor called.");
	this->brain = NULL;
	*this = cat;
}

Cat::~Cat(void)
{
	delete this->brain;
	LOG("Cat died.");
}

Cat& Cat::operator=(const Cat& right)
{
	LOG("Cat assigment operator called.");
	if (this == &right)
		return (*this);
	delete this->brain;
	this->brain = new Brain(*right.brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat: Meowww..." << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}
