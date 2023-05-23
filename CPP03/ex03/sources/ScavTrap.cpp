/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:00:31 by marvin            #+#    #+#             */
/*   Updated: 2023/05/22 23:00:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	LOG("ScavTrap default constructor called.");
	this->setHealth(100);
	this->setEnergy(50);
	this->setDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& trap) : ClapTrap(trap)
{
	LOG("ScavTrap copy constructor called.");
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	LOG("ScavTrap parameter constructor called.");
	this->setHealth(100);
	this->setEnergy(50);
	this->setDamage(20);
}

ScavTrap& ScavTrap::operator=(const ScavTrap& trap)
{
	if (this == &trap)
		return (*this);
	this->setName(trap.getName());
	this->setHealth(trap.getHealth());
	this->setEnergy(trap.getEnergy());
	this->setDamage(trap.getDamage());
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	LOG("ScavTrap destroyed.");
}

//Function to display the numbers from 1 to 100

void ScavTrap::attack(const std::string &target)
{
	if (!this->getEnergy() || !this->getHealth())
	{
		std::cout << "\n\tScavTrap is depleted.\n" << std::endl; 
		return ;
	}

	std::cout << "\n\tScavTrap " << this->getName() << " attacks " << target;
	std::cout << ", causing " << this->getDamage() << " points of damage!\n" << std::endl;
	this->setEnergy(this->getEnergy() - 1);
}

void ScavTrap::guardGate(void)
{
	std::cout << "\n\tScavTrap " << this->getName() << " is in Gate Keeper mode.\n" << std::endl;
}
