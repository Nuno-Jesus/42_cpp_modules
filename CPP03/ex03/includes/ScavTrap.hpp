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

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& trap);
		ScavTrap(const std::string name);
		ScavTrap& operator=(const ScavTrap& trap);
		virtual ~ScavTrap(void);
		virtual void attack(const std::string &target);		
		void guardGate(void);
};

#endif