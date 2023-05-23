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

#include "ClapTrap.hpp"

void usage(void)
{
	std::cout << "Usage: ./claptrap trap_name" << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		usage();
	ClapTrap t1;
	ClapTrap t2(argv[1]);
	ClapTrap t3(t2);

	std::cout << "-------- Testing t3(t2) --------" << std::endl;
	t3.attack("something");
	t3.takeDamage(9);
	t3.beRepaired(5);
	std::cout << t3 << std::endl;

	std::cout << "-------- Testing t1 = t3 --------" << std::endl;
	t1 = t3;
	std::cout << t1 << std::endl;
}