/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:17:55 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 11:17:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	LOG("Cure default constructor called.");
}

Cure::Cure(const Cure& cure) : AMateria(cure.type)
{
	LOG("Cure copy constructor called.");
}

Cure::~Cure(void)
{
	LOG("Cure faded away.");
}

Cure& Cure::operator=(const Cure& cure)
{
	LOG("Cure assignment operator called.");
	if (this == &cure)
		return (*this);
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
