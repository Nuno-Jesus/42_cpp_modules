/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:15:57 by crypto            #+#    #+#             */
/*   Updated: 2023/05/27 12:04:06 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		//! Constructor and destructor
		Weapon();
		Weapon(std::string type);
		~Weapon();

		//! Getters and setters
		void setType(std::string type);
		std::string getType(void) const;

		//! Operator overloading
		Weapon& operator=(const Weapon& right);

	private:
		std::string type;
};

#endif

