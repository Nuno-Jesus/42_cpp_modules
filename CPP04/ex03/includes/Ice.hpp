/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 04:28:02 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 04:28:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		//! Constructors and destructors
		Ice(void);
		Ice(const Ice& ice);
		~Ice(void);

		//! Operator overloading
		Ice& operator=(const Ice& ice);

		//! Others
		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif