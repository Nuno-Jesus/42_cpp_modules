/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:17:54 by crypto            #+#    #+#             */
/*   Updated: 2023/05/30 14:22:12 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	LOG("FragTrap default constructor called.");
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const FragTrap& trap) : ClapTrap(trap)
{
	LOG("FragTrap copy constructor called.");
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	LOG("FragTrap parameter constructor called.");
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap& FragTrap::operator=(const FragTrap& trap)
{
	if (this == &trap)
		return (*this);
	this->name = trap.getName();
	this->health = trap.getHealth();
	this->energy = trap.getEnergy();
	this->damage = trap.getDamage();
	return (*this);
}

FragTrap::~FragTrap(void)
{
	LOG("FragTrap destroyed.");
}

void FragTrap::attack(const std::string &target)
{
	if (!this->energy || !this->health)
	{
		std::cout << "\n\tFragTrap is depleted.\n" << std::endl; 
		return ;
	}
	std::cout << "\n\tFragTrap " << this->getName() << " attacks " << target;
	std::cout << ", causing " << this->getDamage() << " points of damage!\n" << std::endl;
	this->energy--;
}		

void FragTrap::highFiveGuys(void)
{
	std::cout << "\n\tFragTrap " << this->getName() << " high fives everyone ✋!\n" << std::endl;
}	
