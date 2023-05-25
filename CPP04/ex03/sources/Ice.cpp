/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:11:55 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 11:11:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	LOG("Ice default constructor called.");
}

Ice::Ice(const Ice& ice) : AMateria(ice.type)
{
	LOG("Ice copy constructor called.");
}

Ice::~Ice(void)
{
	LOG("Ice faded away.");
}

Ice& Ice::operator=(const Ice& ice)
{
	LOG("Ice assignment operator called.");
	if (this == &ice)
		return (*this);
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
