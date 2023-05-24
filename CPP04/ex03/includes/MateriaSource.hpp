/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:47:34 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 11:47:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"
# include <cstring>

# define SLOTS 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* learntMaterias[SLOTS];
		int numberLearntMaterias;
	
	public:
		//! Constructors and destructor
		MateriaSource(void);
		MateriaSource(const MateriaSource& ms);
		~MateriaSource(void);

		//! Operator overloading
		MateriaSource& operator=(const MateriaSource& right);

		//! Others
		void learnMateria(AMateria *materia);
		AMateria *createMateria(const std::string &type);
};

#endif