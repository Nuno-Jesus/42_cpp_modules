/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:46:06 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 02:46:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		//! Constructors and Destructor
		Cat(void);
		Cat(const Cat& cat);
		virtual ~Cat(void);

		//! Operator overloading
		Cat& operator=(const Cat& cat);

		//! Others
		void makeSound() const;
};

#endif