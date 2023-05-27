/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:48:39 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/19 10:20:39 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstdlib>

class Zombie
{
	public:
		Zombie( void );
		Zombie(std::string name);
		~Zombie();
		void announce( void );

	private:
		std::string name;
};

Zombie* newZombie( std::string name );

void randomChump( std::string name );

#endif
