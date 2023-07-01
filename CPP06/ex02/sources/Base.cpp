/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:03:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/01 16:28:09 by ncarvalh         ###   ########.fr       */
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
		std::cout << "Unknonw type\n";
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Identified A& (" << &a << ")\n";
		return ;
	}
	catch(const std::exception& e)
	{
		
	}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Identified B& (" << &b << ")\n";
		return ;
	}
	catch(const std::exception& e)
	{
		
	}
	
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Identified C& (" << &c << ")\n";
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "Unknown type casting";
	}
	
}

