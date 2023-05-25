/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:05:54 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 11:05:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria()
{
	LOG("AMateria default constructor called.");
}

AMateria::AMateria(const std::string& type)
{
	LOG("AMateria copy constructor called.");
	this->type = type;
}

AMateria::~AMateria()
{
	LOG("AMateria faded away.");
}

const std::string& AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
