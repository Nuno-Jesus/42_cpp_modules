/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:20:28 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 11:20:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	LOG("Character default constructor called.");
	this->inventorySize = 0;
	for (int i = 0; i < SLOTS; i++)
	{
		this->inventory[i] = NULL;
		this->unequiped[i] = NULL;
	}
}

Character::Character(const std::string& name)
{
	LOG("Character parameter constructor called.");
	this->name = name;
	this->inventorySize = 0;
	for (int i = 0; i < SLOTS; i++)
	{
		this->inventory[i] = NULL;
		this->unequiped[i] = NULL;
	}
}

Character::Character(const Character& character)
{
	LOG("Character copy constructor called.");
	this->name = character.name;
	this->inventorySize = character.inventorySize;
	for (int i = 0; i < SLOTS; i++)
	{
		this->inventory[i] = NULL;
		this->unequiped[i] = NULL;
	}
}

Character::~Character(void)
{
	LOG("Character died.");
	for (int i = 0; i < SLOTS; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (this->unequiped[i])
			delete this->unequiped[i];
	}
}

Character& Character::operator=(const Character& right)
{
	if (this == &right)
		return (*this);
	this->name = right.name;
	this->inventorySize = right.inventorySize;
	for (int i = 0; i < SLOTS; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (this->unequiped[i])
			delete this->unequiped[i];
		this->inventory[i] = right.inventory[i];
		this->unequiped[i] = right.unequiped[i];
	}
	return (*this);
}

void Character::equip(AMateria* m)
{
	// Inventory is full and cannot equip anything else
	if (inventorySize > 3)
		return ;

	LOG(this->name + " equiped " + m->getType());
	this->inventory[this->inventorySize++] = m;
}

void Character::unequip(int idx)
{
	// Out of bounds exception
	if (idx < 0 || idx > 3)
		return ;
	
	// Unexisting materia to unequip or full address list
	if (!this->inventory[idx] || this->unequiped[idx] != NULL)
	{
		LOG(this->name + " dropped NULL...");
		return ;
	}
	LOG(this->name + " dropped " + this->inventory[idx]->getType());
	this->unequiped[idx] = this->inventory[idx];
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
	{
		std::cout << this->name << " tried to use NULL materia..." << std::endl;
		return ;
	}
	this->inventory[idx]->use(target);
}

const std::string& Character::getName() const
{
	return (this->name);
}
