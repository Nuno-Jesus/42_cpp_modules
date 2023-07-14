/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:27:31 by crypto            #+#    #+#             */
/*   Updated: 2023/07/14 11:50:19 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB()
{
	this->weapon = NULL;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::attack(void)
{
	if (!this->weapon)
		std::cout << this->name << " attacks with their NULL weapon..." << std::endl;
	else
	{
		std::cout << this->name << " attacks with their ";
		std::cout << this->weapon->getType() << std::endl;		
	}
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
