/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:07:12 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/25 09:22:10 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	usage(void)
{
	std::cout << "Usage: ./zombie hord_size hord_name" << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	int	hordeSize;
	Zombie *horde;
	std::string hordeName;
	
	if (argc < 3)
		usage();
	hordeSize = atoi(argv[1]);
	hordeName = argv[2];
	horde = zombieHorde(hordeSize, hordeName);
	
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
	delete[] horde;
}
