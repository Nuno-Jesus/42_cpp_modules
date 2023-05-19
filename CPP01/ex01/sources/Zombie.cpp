/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:55:50 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/19 11:38:28 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie :: Zombie( void )
{
	
}

Zombie :: Zombie(std::string name)
{
	this->name = name;
}

Zombie :: ~Zombie()
{
	std::cout << this->name << " died." << std::endl;
}

void Zombie :: setName(std::string name)
{
	this->name = name;
}

void Zombie :: announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
