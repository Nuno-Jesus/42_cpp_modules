/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:48:55 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/01 15:57:27 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data = {"Nuno Jesus", 21};

	std::cout << "Hexadecimal Address of data: " << &data << "\n";
	std::cout << "Data = {name = " << data.name << ", age = " << data.age << "}\n\n";
	
	uintptr_t address = Serializer::serialize(&data);
	std::cout << "Serialized address of data: " << address << "\n\n";

	Data *copy = Serializer::deserialize(address);
	std::cout << "Deserialized address of data: " << copy << "\n";
	std::cout << "Copy = {name = " << copy->name << ", age = " << copy->age << "}\n\n";
}
