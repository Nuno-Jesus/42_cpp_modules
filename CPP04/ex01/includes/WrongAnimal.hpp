/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:10:05 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 03:10:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# define DEBUG

# include <iostream>
# ifdef DEBUG
# 	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

class WrongAnimal
{
	protected:
		std::string type;
		
	public:
		//! Constructors and destructor
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& wa);
		virtual ~WrongAnimal(void);

		//! Operator overloading
		WrongAnimal& operator=(const WrongAnimal& right);

		//! Others
		void makeSound() const;

		//! Getters and Setters
		std::string getType(void) const;
		void setType(const std::string& type);
};

#endif