/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:20:49 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 11:20:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <cstring>

# define SLOTS 4

class Character : public ICharacter
{
	private:
		std::string name;
		int	inventorySize;
		AMateria *inventory[SLOTS];
		AMateria *unequiped[SLOTS];

	public:
		//! Copy constructors and destructor
		Character(void);
		Character(const std::string& name);
		Character(const Character& character);
		~Character(void);

		//! Operator overloading
		Character& operator=(const Character& right);

		//! Others
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		//! Getters
		const std::string& getName() const;
};

#endif