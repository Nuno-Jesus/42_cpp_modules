/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:29:16 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/30 12:46:25 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

void	test_increments(void)
{
	Fixed a;
	const Fixed b(Fixed(5.05f) * Fixed(2));
	const Fixed c(Fixed(5.05f) + Fixed(2));
	
	std::cout << "\n\t--- Testing increments ---\n" << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of ++a is: " << ++a << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of a++ is: " << a++ << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of b is: " << b << std::endl;
	std::cout << "The value of c is: " << c << std::endl;
	std::cout << "The maximum between a and b is: " << Fixed::max(a, b) << std::endl;	
}

void	test_decrements(void)
{
	Fixed a;
	const Fixed b(Fixed(5.05f) / Fixed(2));
	const Fixed c(Fixed(5.05f) - Fixed(2));
	
	std::cout << "\n\t--- Testing decrements ---\n" << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of --a is: " << --a << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of a-- is: " << a-- << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of b is: " << b << std::endl;
	std::cout << "The value of c is: " << c << std::endl;
	std::cout << "The minimum between a and b is: " << Fixed::min(a, b) << std::endl;	
}

void test_comparisons(void)
{
	Fixed a(5.5f);	
	Fixed b(5.2f);	

	std::cout << "\n\t--- Testing comparison ---\n" << std::endl;
	
	if (a != b)
		std::cout << "A(" << a << ") != B(" << b << ")" << std::endl;
	else	
		std::cout << "A(" << a << ") == B(" << b << ")" << std::endl;
	if (a > b)
		std::cout << "A(" << a << ") > B(" << b << ")" << std::endl;
	if (a < b)
		std::cout << "A(" << a << ") < B(" << b << ")" << std::endl;
	if (a >= b)
		std::cout << "A(" << a << ") >= B(" << b << ")" << std::endl;
	if (a <= b)
		std::cout << "A(" << a << ") <= B(" << b << ")" << std::endl;
}

int main(void)
{
	test_increments();
	test_decrements();
	test_comparisons();
	return 0;
}
