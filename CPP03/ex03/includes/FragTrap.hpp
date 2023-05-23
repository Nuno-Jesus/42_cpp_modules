/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:15:53 by crypto            #+#    #+#             */
/*   Updated: 2023/05/23 12:00:01 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap& trap);
		FragTrap(const std::string name);
		FragTrap& operator=(const FragTrap& trap);
		~FragTrap(void);
		void attack(const std::string &target);		
		void highFiveGuys(void);
};

#endif