/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:15:53 by crypto            #+#    #+#             */
/*   Updated: 2023/05/27 19:04:03 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		//! Constructors and destructor
		FragTrap(void);
		FragTrap(const FragTrap& trap);
		FragTrap(const std::string name);
		virtual ~FragTrap(void);
		
		//! Operator overloading
		FragTrap& operator=(const FragTrap& trap);

		//! Others
		void attack(const std::string &target);		
		void highFiveGuys(void);
};

#endif
