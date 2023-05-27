/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:37:06 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 02:37:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP


# include <iostream>
# include "Brain.hpp"

# define DEBUG

# ifdef DEBUG
# 	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

class Animal
{
	protected:
		std::string type;
		
	public:
		//! Constructors and destructor
		Animal(void);
		Animal(const Animal& animal);
		virtual ~Animal(void);

		//! Operator overloading
		Animal& operator=(const Animal& right);

		//! Others
		virtual void makeSound() const = 0;

		//! Getters and Setters
		std::string getType(void) const;
		void setType(const std::string& type);
};

#endif
