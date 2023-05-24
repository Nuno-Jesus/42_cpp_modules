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
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
		
	public:
		//! Constructors and Destructor
		Dog(void);
		Dog(const Dog& right);
		virtual ~Dog(void);

		//! Operator overloading
		Dog& operator=(const Dog& right);

		//! Others
		void makeSound() const;

		//! Getter
		Brain *getBrain(void) const;
};

#endif