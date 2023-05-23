/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:15:53 by crypto            #+#    #+#             */
/*   Updated: 2023/05/23 19:26:51 by marvin           ###   ########.fr       */
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
		virtual ~FragTrap(void);
		void attack(const std::string &target);		
		void highFiveGuys(void);
};

#endif