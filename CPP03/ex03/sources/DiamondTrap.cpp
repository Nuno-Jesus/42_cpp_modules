/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:50:26 by crypto            #+#    #+#             */
/*   Updated: 2023/05/23 12:10:16 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	LOG("DiamondTrap constructor called.");
}

DiamondTrap::DiamondTrap(const std::string& name, const std::string& name_clap_trap) :
	FragTrap(name_clap_trap), ScavTrap(name_clap_trap), ClapTrap(name_clap_trap)
{
	LOG("DiamondTrap parameter constructor called.");
	this->name = name;
	this->setHealth(FragTrap::getHealth());
	this->setEnergy(ScavTrap::getEnergy());
	this->setDamage(FragTrap::getDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap& trap)
{
	LOG("DiamondTrap copy constructor called.");
}

DiamondTrap::~DiamondTrap()
{
	LOG("DiamondTrap destroyed.");
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& right)
{

}

void DiamondTrap::whoAmI()
{
	
}
