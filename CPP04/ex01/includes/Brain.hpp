/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:25:07 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 03:25:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# ifdef DEBUG
# 	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

# include <iostream>
# include <cstdlib>

# define NUM_IDEAS 100

class Brain
{
	private:
		std::string ideas[NUM_IDEAS];
	
	public:
		//! Constructors and destructors
		Brain(void);
		Brain(const Brain& brain);
		~Brain(void);

		//! Operator overloading
		Brain& operator=(const Brain& right);
};

#endif
