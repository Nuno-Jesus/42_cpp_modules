/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:09:08 by marvin            #+#    #+#             */
/*   Updated: 2023/05/22 22:09:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>

# define DEBUG

# ifdef DEBUG
#	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

class ClapTrap
{
	private:
		std::string name;
		int	health;
		int energy;
		int damage;
		
	public:
		//! Constructors
		ClapTrap(void);
		ClapTrap(const ClapTrap& trap);
		ClapTrap(const std::string& name);
		~ClapTrap(void);

		//! Others
		ClapTrap& operator=(const ClapTrap& right);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		//! Getters
		std::string getName(void) const;
		int getHealth(void) const;
		int getEnergy(void) const;
		int getDamage(void) const;

		//! Setters
		void setName(std::string name);
		void setHealth(int health);
		void setEnergy(int energy);
		void setDamage(int damage);
};

std::ostream& operator<<(std::ostream& out, const ClapTrap& right);

#endif