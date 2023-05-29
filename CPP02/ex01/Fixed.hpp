/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:01:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/29 14:32:31 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <cmath>

class Fixed
{
	private:
		int value;
		static const int BITS = 8;
		
	public:
		//! Constructors and destructors
		Fixed();
		Fixed(const Fixed &num);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();

		//! Others
		float toFloat(void) const;
		int toInt(void) const;

		//! Getters and setters 
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		//! Operator overloading
		Fixed& operator=(const Fixed& right);
};

std::ostream& operator<<(std::ostream& out, const Fixed& right);

#endif
