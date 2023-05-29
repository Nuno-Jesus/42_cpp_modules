/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:01:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/29 14:32:18 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int value;
		static const int BITS = 8;
		
	public:
		//! Constructors and destructor
		Fixed();
		Fixed(Fixed &num);
		~Fixed();

		//! Operator overloading
		Fixed& operator=(Fixed &right);

		//! Getters and setters
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
