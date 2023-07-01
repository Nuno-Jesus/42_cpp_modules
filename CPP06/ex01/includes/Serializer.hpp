/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:45:32 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/01 15:58:14 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
//Include the necessary library to use uintptr_t
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
	private:
		//! Constructors and destructor
		Serializer();
		Serializer(const Serializer& copy);
		~Serializer();

		//! Operator overloading
		Serializer& operator=(const Serializer& right);
};

#endif
