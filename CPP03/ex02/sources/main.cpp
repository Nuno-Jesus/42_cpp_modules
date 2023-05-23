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

#include "FragTrap.hpp"

void usage(void)
{
	std::cout << "Usage: ./fragptrap trap_name" << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		usage();
	FragTrap t1;
	FragTrap t2(argv[1]);
	FragTrap t3(t2);

	std::cout << "-------- Testing t3(t2) --------" << std::endl;
	t3.attack("something");
	t3.takeDamage(9);
	t3.beRepaired(5);
	t3.highFiveGuys();
	std::cout << t3 << std::endl;

	std::cout << "-------- Testing t1 = t3 --------" << std::endl;
	t1 = t3;
	std::cout << t1 << std::endl;
}