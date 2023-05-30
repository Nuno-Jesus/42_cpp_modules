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

#include "ScavTrap.hpp"

void usage(void)
{
	std::cout << "Usage: ./ex01 trap_name" << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		usage();
	ScavTrap t1;
	ScavTrap t2(argv[1]);
	ScavTrap t3(t2);

	std::cout << "-------- Testing t3(t2) --------\n" << std::endl;
	t3.attack("John Cena");
	std::cout << t3;
	t3.takeDamage(9);
	std::cout << t3;
	t3.beRepaired(5);
	std::cout << t3;
	t3.guardGate();
	std::cout << t3;
	t3.takeDamage(100);
	std::cout << t3;
	t3.beRepaired(50);
	std::cout << t3;
	
	std::cout << "\n-------- Testing t1 = t3 --------\n" << std::endl;
	t1 = t3;
	std::cout << t1;
}
