/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:52:14 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/16 15:54:04 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <iomanip>

class RPN
{
	//! _______________________ PRIVATE FIELDS _______________________
	private:

	public:
	//! ________________________ CONSTRUCTORS ________________________
		RPN();
		RPN(const RPN& copy);
		~RPN();

	//! ____________________ OPERATOR OVERLOADING ____________________
		RPN& operator=(const RPN& right);
	//! __________________________ SETTERS ___________________________

	//! __________________________ GETTERS ___________________________

	//! _________________ PRIVATE MEMBER FUNCTIONS ___________________
	private:
};

#endif