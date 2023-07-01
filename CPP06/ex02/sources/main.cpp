/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:07:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/01 16:27:52 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	Base *random;

	std::srand(time(NULL));
	
	random = generate();
	//Print the address contained in random
	std::cout << "Address of random: " << random << std::endl;
	identify(random);
	identify(*random);
	
	delete random;
}
