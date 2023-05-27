/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:00:43 by marvin            #+#    #+#             */
/*   Updated: 2023/05/22 23:00:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		//! Constructors and destructor
		ScavTrap(void);
		ScavTrap(const ScavTrap& trap);
		ScavTrap(const std::string name);
		virtual ~ScavTrap(void);

		//! Operator overloading
		ScavTrap& operator=(const ScavTrap& trap);

		//! Others
		void attack(const std::string &target);		
		void guardGate(void);
};

#endif
