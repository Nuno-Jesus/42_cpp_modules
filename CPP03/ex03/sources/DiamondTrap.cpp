/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:50:26 by crypto            #+#    #+#             */
/*   Updated: 2023/05/30 14:27:34 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	LOG("DiamondTrap default constructor called.");
	this->name = "Nameless";
	this->health = 100;
	this->energy = 50;
	this->damage = 30;
	this->ClapTrap::name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	LOG("DiamondTrap parameter constructor called.");
	this->name = name;
	this->health = 100;
	this->energy = 50;
	this->damage = 30;
	this->ClapTrap::name = name + "_clap_name";
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
	this->health = right.health;
	this->energy = right.energy;
	this->damage = right.damage;
	this->ClapTrap::name = right.ClapTrap::name;
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "\n\tDiamondTrap " << this->name;
	std::cout << " is also known as ClapTrap " << ClapTrap::name;
	std::cout << std::endl << std::endl;
}
