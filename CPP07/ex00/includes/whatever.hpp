/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:54:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/22 17:56:57 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp; 
}

template <typename T>
T max(T a, T b)
{
	return (a > b ? a : b);
}

template <typename T>
T min(T a, T b)
{
	return (a < b ? a : b);
}
