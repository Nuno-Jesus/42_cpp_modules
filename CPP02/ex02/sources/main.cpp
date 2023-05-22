/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:29:16 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/22 12:58:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

void	test_increments(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(Fixed(5.05f) + Fixed(2));
	
	std::cout << "\n\t--- Testing increments ---\n" << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of ++a is: " << ++a << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of a++ is: " << a++ << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	
	std::cout << "The value of c is: " << c << std::endl;
	std::cout << "The maximum between a and b is: " << Fixed::max(a, b) << std::endl;	
}

void	test_decrements(void)
{
	Fixed a;
	Fixed b(Fixed(5.05f) / Fixed(2));
	Fixed c(Fixed(5.05f) - Fixed(2));
	
	std::cout << "\n\t--- Testing decrements ---\n" << std::endl;
	std::cout << "The value of b is: " << b << std::endl;
	std::cout << "The value of --b is: " << --b << std::endl;
	std::cout << "The value of b is: " << b << std::endl;
	std::cout << "The value of b-- is: " << b-- << std::endl;
	std::cout << "The value of b is: " << b << std::endl;
	std::cout << "The value of c is: " << c << std::endl;
	
	std::cout << "The minimum between a and b is: " << Fixed::min(a, b) << std::endl;	
}

void test_comparisons(void)
{
	Fixed a(5.5f);	
	Fixed b(5.7f);	

	std::cout << "\n\t--- Testing comparison ---\n" << std::endl;
	if (a != b)
	{
		if (a > b)
			std::cout << "A(" << a << ") is greater than B(" << b << ")" << std::endl;
		if (a < b)
			std::cout << "A(" << a << ") is less than B(" << b << ")" << std::endl;
	}
	else	
		std::cout << "A(" << a << ") is equal to B(" << b << ")" << std::endl;
}

int main(void)
{
	test_increments();
	test_decrements();
	test_comparisons();
	return 0;
}
