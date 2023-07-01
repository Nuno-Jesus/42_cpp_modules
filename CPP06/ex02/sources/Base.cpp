/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:03:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/01 16:44:57 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base()
{
	
}

Base * generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "Generated instance of A*\n";
			return (new A());
		case 1:
			std::cout << "Generated instance of B*\n";
			return (new B());
		case 2:
			std::cout << "Generated instance of C*\n";
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A*\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B*\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C*\n";
	else
		std::cout << "Unknown pointer\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified A&\n";
		return ;
	}
	catch(const std::exception& e)
	{
		
	}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identified B&\n";
		return ;
	}
	catch(const std::exception& e)
	{
		
	}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identified C&\n";
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "Unknown type casting\n";
	}
	
}

