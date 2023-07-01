/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:54:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/01 17:32:55 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void iter(T *array, int len, void (*f)(T))
{
	for (int i = 0; i < len; i++)
		(*f)(array[i]);	
}
