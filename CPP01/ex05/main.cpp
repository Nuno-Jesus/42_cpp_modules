/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:50:11 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/20 16:52:08 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void usage(void)
{
	std::cout << "Usage: ./harl level" << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	Harl harl;
	std::string level;
	
	if (argc < 2)
		usage();
	level = argv[1];
	harl.complain(level);
	return (0);
}
