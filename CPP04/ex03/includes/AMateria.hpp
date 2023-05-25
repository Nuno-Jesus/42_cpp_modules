/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 04:23:31 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 04:23:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

# define DEBUG

# ifdef DEBUG
# 	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

class ICharacter;

class AMateria
{
	protected:
		std::string type;

	public:
		//! Constructors and destructors
		AMateria(); 
		AMateria(const std::string& type);
		virtual ~AMateria();
		
		//! Getter
		const std::string& getType() const;
		
		//! Others
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif

