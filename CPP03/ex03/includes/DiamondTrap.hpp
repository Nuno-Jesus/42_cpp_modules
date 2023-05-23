/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:40:37 by crypto            #+#    #+#             */
/*   Updated: 2023/05/23 11:52:13 by crypto           ###   ########.fr       */
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
		DiamondTrap();
		DiamondTrap(const std::string& name, const std::string& name_clap_trap);
		DiamondTrap(const DiamondTrap& trap);
		~DiamondTrap();

		//! Operator overloading
		DiamondTrap& operator=(const DiamondTrap& right);

		//!Others
		void whoAmI();
		
				
};

#endif