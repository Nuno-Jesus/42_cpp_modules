/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:07:12 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/19 11:42:37 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	usage(void)
{
	std::cout << "Usage: hord_size hord_name" << std::endl;
	exit(-1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		usage();

	int	size = atoi(argv[1]);
	std::string hordeName = argv[2];
	Zombie *horde = zombieHorde(size, hordeName);
	
	for (int i = 0; i < size; i++)
		horde[i].announce();
	
	delete [] horde;
}
