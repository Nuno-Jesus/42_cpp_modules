/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:11:55 by marvin            #+#    #+#             */
/*   Updated: 2023/05/22 22:11:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	LOG("ClapTrap default constructor called.");
	this->health = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& trap)
{
	LOG("ClapTrap copy constructor called.");
	*this = trap;
}

ClapTrap::ClapTrap(const std::string& name)
{
	LOG("ClapTrap parameter constructor called.");
	this->name = name;
	this->health = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::~ClapTrap()
{
	LOG("ClapTrap destroyed.");
}

ClapTrap& ClapTrap::operator=(const ClapTrap& right)
{
	if (this == &right)
		return (*this);
	this->name = right.getName();
	this->health = right.getHealth();
	this->energy = right.getEnergy();
	this->damage = right.getDamage();
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->energy || !this->health)
	{
		std::cout << "\n\tClapTrap is depleted.\n" << std::endl; 
		return ;
	}
	std::cout << "\n\tClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->damage << " points of damage!\n";
	std::cout << std::endl;
	this->energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->health = this->health - amount;
	if (this->health < 0)
		this->health = 0;
	std::cout << "\n\tClapTrap " << this->name << " received " << amount;
	std::cout << " damage, dropping the HP to " << this->health << "!\n";
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->energy || !this->health)
	{
		std::cout << "\n\tClapTrap is depleted.\n" << std::endl; 
		return ;
	}
	this->health = this->health + amount;	
	std::cout << "\n\tClapTrap " << this->name << " healed " << amount;
	std::cout << " HP, increasing the HP to " << this->health << "!\n";
	std::cout << std::endl;
	this->energy--;
}

std::string ClapTrap::getName(void) const
{
	return (this->name);
}

int ClapTrap::getHealth(void) const
{
	return (this->health);
}

int ClapTrap::getEnergy(void) const
{
	return (this->energy);
}

int ClapTrap::getDamage(void) const
{
	return (this->damage);
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

void ClapTrap::setHealth(int health)
{
	this->health = health;
}

void ClapTrap::setEnergy(int energy)
{
	this->energy = energy;
}

void ClapTrap::setDamage(int damage)
{
	this->damage = damage;
}

std::ostream& operator<<(std::ostream& out, const ClapTrap& right)
{
	out << "ClapTrap Name (" << right.getName() << "): " << std::endl;
	out << " - Health: " << right.getHealth() << std::endl;
	out << " - Energy: " << right.getEnergy() << std::endl;
	out << " - Damage: " << right.getDamage() << std::endl;
	return (out);
}