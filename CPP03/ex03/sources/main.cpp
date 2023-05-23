/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:26:04 by marvin            #+#    #+#             */
/*   Updated: 2023/05/22 22:26:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void usage(void)
{
	std::cout << "Usage: ./DiamondTrap trap_name" << std::endl;
	exit(1);
}

int menu(const DiamondTrap &trap)
{
	int option;

	std::cout << trap << std::endl;
	std::cout << "Available options:" << std::endl;
	std::cout << "1 -> Attack" << std::endl;
	std::cout << "2 -> Repair" << std::endl;
	std::cout << "3 -> Take damage" << std::endl;
	std::cout << "4 -> Guard gate" << std::endl;
	std::cout << "5 -> High five" << std::endl;
	std::cout << "6 -> Who am I" << std::endl;
	std::cout << "7 -> Exit" << std::endl;
	std::cout << "Option: ";
	std::cin >> option;
	std::cin.ignore(1000, '\n');
	return (option);
}


int main(int argc, char **argv)
{
	if (argc < 2)
		usage();

	DiamondTrap t(argv[1]);
	DiamondTrap trap(t);
	std::string target;
	int tmp;

	while (1)
	{
		tmp = menu(trap);
		switch(tmp)
		{
			case 1:
				std::cout << "Pick a target: ";
				std::getline(std::cin, target);
				trap.attack(target);
				break;
			case 2:
				std::cout << "Points to heal: ";
				std::cin >> tmp;
				std::cin.ignore(1000, '\n');
				trap.beRepaired(tmp);
				break;
			case 3:
				std::cout << "Amount of damage: ";
				std::cin >> tmp;
				std::cin.ignore(1000, '\n');
				trap.takeDamage(tmp);
				break;
			case 4:
				trap.guardGate();
				break;
			case 5:
				trap.highFiveGuys();
				break;
			case 6:
				trap.whoAmI();
				break;
			case 7:
				return (0);
				break;
			default:
				break;
		}
	}
}