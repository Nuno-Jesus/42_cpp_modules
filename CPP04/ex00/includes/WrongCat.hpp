/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:10:57 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 03:10:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		//! Constructors and Destructor
		WrongCat(void);
		WrongCat(const WrongCat& wc);
		virtual ~WrongCat(void);

		//! Operator overloading
		WrongCat& operator=(const WrongCat& right);

		//! Others
		void makeSound() const;
};

#endif
