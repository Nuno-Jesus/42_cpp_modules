/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:07:12 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/27 13:59:00 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	usage(void)
{
	std::cout << "Usage: ./zombie hord_size(>= 0) hord_name" << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 3)
		usage();
		
	int	hordeSize;
	Zombie *horde;
	
	hordeSize = atoi(argv[1]);
	horde = zombieHorde(hordeSize, argv[2]);
	if (!horde)
		return (2);
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
	delete[] horde;
}
