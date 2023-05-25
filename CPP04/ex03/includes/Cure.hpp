/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:02:47 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 11:02:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		//! Constructors and destructors
		Cure(void);
		Cure(const Cure& cure);
		~Cure(void);

		//! Operator overloading
		Cure& operator=(const Cure& cure);

		//! Others
		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif
