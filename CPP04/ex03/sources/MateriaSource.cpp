/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:54:57 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 11:54:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	LOG("MateriaSource default constructor called.");
	this->numberLearntMaterias = 0;
	memset(this->learntMaterias, 0, SLOTS * sizeof(AMateria *));
}

MateriaSource::MateriaSource(const MateriaSource& ms)
{
	LOG("MateriaSource copy constructor called.");
	*this = ms;
}

MateriaSource::~MateriaSource(void)
{
	LOG("MateriaSource faded away.");
	for (int i = 0; i < this->numberLearntMaterias; i++)
		delete learntMaterias[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& right)
{
	LOG("MateriaSource assingment operator called.");
	if (this == &right)
		return (*this);

	for (int i = 0; i < this->numberLearntMaterias; i++)
		delete learntMaterias[i];
	this->numberLearntMaterias = right.numberLearntMaterias;
	memcpy(this->learntMaterias, right.learntMaterias, SLOTS * sizeof(AMateria *));
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	// Cannot learn more materias
	if (numberLearntMaterias >= SLOTS)
		return ;

	LOG("MateriaSource learned " + materia->getType());
	this->learntMaterias[this->numberLearntMaterias++] = materia;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0 ; i < this->numberLearntMaterias; i++)
		if (this->learntMaterias[i]->getType() == type)
			return (this->learntMaterias[i]->clone());
	return (NULL);
}
