/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:25:32 by marvin            #+#    #+#             */
/*   Updated: 2023/05/21 22:25:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& p);
		~Point();
		Point& operator=(const Point& p);		
		bool operator==(const Point& p);
		Fixed getX() const;
		Fixed getY() const;
};

#endif
