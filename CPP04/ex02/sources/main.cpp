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
#include "WrongCat.hpp"

void test_wrong_inheritance(void)
{
	std::cout << "\n\t=== Testing wrong inheritance of an animal ===\n" << std::endl;
	
	const WrongAnimal *animal = new WrongAnimal();
	const WrongAnimal *cat = new WrongCat();

	animal->makeSound();
	cat->makeSound();

	delete cat;
	delete animal;
}

void test_animal_copy(void)
{	
	std::cout << "\n\t=== Testing a copy of an animal ===\n" << std::endl;
	
	const Animal *dog = new Dog();
	const Animal *copy = dog;

	std::cout << copy->getType() << std::endl;
	copy->makeSound();

	delete dog;
}

void test_inheritance(void)
{
	std::cout << "\n\t=== Testing new animals growls ===\n" << std::endl;
	
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
}

int main()
{
	//! This will give a compilation error
	// Animal test;
	test_inheritance();
	test_animal_copy();
	test_wrong_inheritance();
}
