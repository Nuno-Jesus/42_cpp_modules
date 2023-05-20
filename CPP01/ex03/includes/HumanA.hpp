/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:21:31 by crypto            #+#    #+#             */
/*   Updated: 2023/05/19 12:31:16 by crypto           ###   ########.fr       */
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
		HumanA(std::string name, Weapon weapon);
		void attack(void);
		void setWeapon(Weapon weapon);
		
	private:
		std::string name;
		Weapon weapon;
};

#endif
