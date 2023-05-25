/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:21:26 by crypto            #+#    #+#             */
/*   Updated: 2023/05/25 09:35:23 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA()
{
	this->weapon = Weapon();
}

HumanA::HumanA(const std::string& name, const Weapon& weapon)
{
	this->name = name;
	this->weapon = weapon;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}
