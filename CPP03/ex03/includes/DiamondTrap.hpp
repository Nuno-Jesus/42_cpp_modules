/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:40:37 by crypto            #+#    #+#             */
/*   Updated: 2023/05/23 20:58:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
		
	public:
		//! Constructors and destructors
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& trap);
		~DiamondTrap(void);

		//! Operator overloading
		DiamondTrap& operator=(const DiamondTrap& right);

		//!Others
		void attack(const std::string& target);
		void whoAmI(void);
};

#endif