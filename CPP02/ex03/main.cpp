/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:29:16 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/27 18:28:50 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(10, 30);
	Point b(0, 0);
	Point c(20, 0);
	float x;
	float y;

	std::cout << "Input x and y (x y): ";
	std::cin >> x >> y;
	if (std::cin.fail())
	{
		std::cout << "\n\tBad input\n" << std::endl;
		return (EXIT_FAILURE);
	}
	
	if (bsp(a, b, c, Point(x, y)))
		std::cout << "(" << x << "," << y << ") is inside the triangle" << std::endl;
	else
		std::cout << "(" << x << "," << y << ") is outside the triangle" << std::endl;
	return 0;
}
