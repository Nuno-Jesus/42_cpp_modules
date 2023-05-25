/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:46:06 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 02:46:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		//! Constructors and Destructor
		Dog(void);
		Dog(const Dog& dog);
		virtual ~Dog(void);

		//! Operator overloading
		Dog& operator=(const Dog& dog);

		//! Others
		void makeSound() const;
};

#endif
