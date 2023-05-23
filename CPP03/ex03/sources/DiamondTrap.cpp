/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:50:26 by crypto            #+#    #+#             */
/*   Updated: 2023/05/23 19:50:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	LOG("DiamondTrap constructor called.");
}

DiamondTrap::DiamondTrap(const std::string& name)
{
	LOG("DiamondTrap parameter constructor called.");
	this->name = name;
	this->setHealth(FragTrap::getHealth());
	this->setEnergy(ScavTrap::getEnergy());
	this->setDamage(FragTrap::getDamage());
	this->setName(name + "_clap_name");
}

DiamondTrap::DiamondTrap(const DiamondTrap& trap) : ClapTrap(trap), ScavTrap(trap), FragTrap(trap) 
{
	LOG("DiamondTrap copy constructor called.");
	this->name = trap.name;
}

DiamondTrap::~DiamondTrap(void)
{
	LOG("DiamondTrap destroyed.");
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& right)
{
	if (this == &right)
		return (*this);
	this->name = right.name;
	this->setHealth(right.FragTrap::getHealth());
	this->setEnergy(right.ScavTrap::getEnergy());
	this->setDamage(right.FragTrap::getDamage());
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "\n\tDiamondTrap " << this->name;
	std::cout << " is also known as ClapTrap " << ClapTrap::getName();
	std::cout << std::endl << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
