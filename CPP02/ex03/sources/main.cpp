/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:29:16 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/22 00:03:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	Point a(10, 30);
	Point b(0, 0);
	Point c(20, 0);
	float x;
	float y;

	std::cout << "Input x and y (x y): ";
	std::cin >> x >> y;
	
	if (bsp(a, b, c, Point(x, y)))
		std::cout << "(" << x << "," << y << ") is inside the triangle" << std::endl;
	else
		std::cout << "(" << x << "," << y << ") is outside the triangle" << std::endl;
	return 0;
}

/*
If P(30, 15):
			  B(10,30)
                / \
               /   \
              /     \
             /       \      P
            /         \
     A(0,0) ----------- C(20,0) 

If P(10, 15):
			  B(10,30)
                / \
               /   \
              /     \
             /   P   \      
            /         \
     A(0,0) ----------- C(20,0) 

 */
