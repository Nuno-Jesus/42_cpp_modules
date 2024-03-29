/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:07:12 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/27 15:39:49 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	usage(void)
{
	std::cout << "Usage: ./zombie name_of_random_chump name_of_new_zombie" << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	std::string randomName;
	std::string newZombieName;

	if (argc < 3)
		usage();

	randomName = argv[1];
	newZombieName = argv[2];

	//Spawn and announce the random zombie
	std::cout << "\n\t---- Random Chump ----\n\n";
	randomChump(randomName);

	//Create a new heap zombie to be used in main
	std::cout << "\n\t---- New Zombie ----\n\n";
	Zombie *zombie = newZombie(newZombieName);
	zombie->announce();
	delete zombie;
}
