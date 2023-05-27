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

	std::cout << "\n-------- Testing t3(t2) --------" << std::endl;
	t3.attack("something");
	std::cout << t3;
	t3.takeDamage(9);
	std::cout << t3;
	t3.beRepaired(5);
	std::cout << t3;
	t3.highFiveGuys();
	std::cout << t3;

	std::cout << "\n-------- Testing t1 = t3 --------\n" << std::endl;
	t1 = t3;
	std::cout << t1;
}
