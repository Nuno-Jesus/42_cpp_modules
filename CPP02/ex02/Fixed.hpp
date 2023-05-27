/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:01:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/27 18:16:40 by ncarvalh         ###   ########.fr       */
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
		//! Constructors and destructor
		Fixed();
		Fixed(const Fixed &num);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();

		//! Getters and setters
		int getRawBits(void) const;
		void setRawBits(int const raw);

		//! Conversions
		float toFloat(void) const;
		int toInt(void) const;

		//! Operators overloading
		Fixed& operator=(const Fixed &right);
		bool operator>(const Fixed& right);
		bool operator<(const Fixed& right);
		bool operator>=(const Fixed& right);
		bool operator<=(const Fixed& right);
		bool operator==(const Fixed& right);
		bool operator!=(const Fixed& right);
		Fixed operator+(const Fixed& right);
		Fixed operator-(const Fixed& right);
		Fixed operator*(const Fixed& right);
		Fixed operator/(const Fixed& right);
		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int dummy);
		Fixed operator--(int dummy);

		//! Min and max functions
		static Fixed& min(Fixed& f1, Fixed& f2);
		static Fixed& max(Fixed& f1, Fixed& f2);
		static const Fixed& min(const Fixed& f1, const Fixed& f2);
		static const Fixed& max(const Fixed& f1, const Fixed& f2);

};

std::ostream& operator<<(std::ostream& out, const Fixed& right);

#endif
