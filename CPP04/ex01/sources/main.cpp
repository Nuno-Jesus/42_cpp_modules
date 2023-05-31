/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:57:07 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 02:57:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <ctime>

void test_animal_copies(void)
{
	std::cout << "\n\t=== Testing shallow/deep copies ===\n" << std::endl;
	
	Cat *cat = new Cat();
	Cat *clone = new Cat(*cat);

	std::cout << "\n\tCats brain: " << cat->getBrain() << std::endl << std::endl;
	// cat->getBrain()->use();
	delete cat;

	std::cout << "\tClone cat brain: " << clone->getBrain() << std::endl << std::endl;
	// clone->getBrain()->use();
	delete clone;

	std::cout << std::endl;
}

void test_destructors(void)
{
	std::cout << "\n\t=== Testing destructors ===\n" << std::endl;
	
	Animal *animals[4] = 
	{
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat()
	};

	for (int i = 0; i < 4; i++)
		delete animals[i];
}

int main()
{
	std::srand(std::time(NULL));
	test_animal_copies();
	test_destructors();	
}
