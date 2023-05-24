/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:12:07 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 03:12:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	LOG("WrongCat default constructor called.");
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wc) : WrongAnimal(wc)
{
	LOG("WrongCat copy constructor called.");
}

WrongCat::~WrongCat(void)
{
	LOG("WrongCat died.");
}

WrongCat& WrongCat::operator=(const WrongCat& right)
{
	LOG("WrongCat assigment operator called.");
	if (this == &right)
		return (*this);
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat: Meowww..." << std::endl;
}