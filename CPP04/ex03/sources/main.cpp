/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:07:56 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 12:07:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	test_copy_constructors(void)
{
	std::cout << "\n\t======= Testing copy constructors =======\n" << std::endl;
	IMateriaSource *source = new MateriaSource();

	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

	Ice *ice = new Ice();
	Ice *iceCopy = new Ice(*ice);

	Cure *cure = new Cure();
	Cure *cureCopy = new Cure(*cure);

	delete source;
	delete ice;
	delete iceCopy;
	delete cure;
	delete cureCopy;
}

void	test_all_together(void)
{
	std::cout << "\n\t======= Testing all together =======\n" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	
	delete bob;
	delete me;
	delete src;
}

int main()
{
	test_copy_constructors();
	test_all_together();
	return 0;
}
