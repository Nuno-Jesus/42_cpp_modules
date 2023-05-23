/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:17:54 by crypto            #+#    #+#             */
/*   Updated: 2023/05/23 19:18:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	LOG("FragTrap constructor called.");
	this->setHealth(100);
	this->setEnergy(100);
	this->setDamage(30);
}

FragTrap::FragTrap(const FragTrap& trap) : ClapTrap(trap)
{
	LOG("FragTrap copy constructor called.");
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	LOG("FragTrap parameter constructor called.");
	this->setHealth(100);
	this->setEnergy(100);
	this->setDamage(30);
}

FragTrap& FragTrap::operator=(const FragTrap& trap)
{
	if (this == &trap)
		return (*this);
	this->setName(trap.getName());
	this->setHealth(trap.getHealth());
	this->setEnergy(trap.getEnergy());
	this->setDamage(trap.getDamage());	
	return (*this);
}

FragTrap::~FragTrap(void)
{
	LOG("FragTrap destroyed.");	
}

void FragTrap::attack(const std::string &target)
{
	if (!this->getEnergy() || !this->getHealth())
	{
		std::cout << "\n\tFragTrap is depleted.\n" << std::endl; 
		return ;
	}

	std::cout << "\n\tFragTrap " << this->getName() << " attacks " << target;
	std::cout << ", causing " << this->getDamage() << " points of damage!\n" << std::endl;
	this->setEnergy(this->getEnergy() - 1);
}		

void FragTrap::highFiveGuys(void)
{
	std::cout << "\n\tFragTrap " << this->getName() << " requested high five!\n" << std::endl;
}	
