/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:01:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/21 09:11:14 by ncarvalh         ###   ########.fr       */
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
		static const int FRACTION_BITS = 8;
		
	public:
		Fixed();
		Fixed(const Fixed &num);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed& operator=(const Fixed &right);

};

std::ostream& operator<<(std::ostream& out, const Fixed& right);

#endif
