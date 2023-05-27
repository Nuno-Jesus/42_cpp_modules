/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:10:34 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/27 13:53:00 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstdlib>

// # define DEBUG

# ifdef DEBUG
#	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

class Harl
{
	public:
		//! Constructor
		Harl(void);
		~Harl(void);

		//! Others
		void complain (std::string level);
		
	private:
		//! Others
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
