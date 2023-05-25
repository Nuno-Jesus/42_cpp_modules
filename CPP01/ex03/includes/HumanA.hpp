/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:21:31 by crypto            #+#    #+#             */
/*   Updated: 2023/05/25 09:34:08 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA();
		HumanA(const std::string& name, const Weapon& weapon);
		void attack(void);
		void setWeapon(Weapon& weapon);
		
	private:
		std::string name;
		Weapon& weapon;
};

#endif
