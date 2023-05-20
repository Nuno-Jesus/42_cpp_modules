/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:31:34 by crypto            #+#    #+#             */
/*   Updated: 2023/05/20 17:17:25 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates an array of heap allocated Zombie objects
// Line 19 is the same as ... = malloc(10 * sizeof(Zombie))
Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	
	for(int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
