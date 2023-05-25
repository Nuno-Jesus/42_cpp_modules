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
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	LOG("Cat copy constructor called.");
}

Cat::~Cat(void)
{
	LOG("Cat died.");
}

Cat& Cat::operator=(const Cat& cat)
{
	LOG("Cat assigment operator called.");
	if (this == &cat)
		return (*this);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat: Meowww..." << std::endl;
}
