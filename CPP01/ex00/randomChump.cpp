/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:53:15 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/20 17:14:01 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates a temporary object that is destroyed after the function
// has terminated
void randomChump( std::string name )
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}
