/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:50:11 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/20 17:08:36 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void usage(void)
{
	std::cout << "Usage: ./harl level" << std::endl;
	exit(1);
}

void harlFilter(Harl harl, std::string level)
{	
	std::string levels[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int index;
	
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			index = i;
	switch(index)
	{
		default:
			break;
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
	}
}

int main(int argc, char **argv)
{
	Harl 		harl;
	std::string level;
	
	if (argc < 2)
		usage();
	level = argv[1];
	harlFilter(harl, level);
	return (0);
}
