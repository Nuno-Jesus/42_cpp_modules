/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:52:15 by marvin            #+#    #+#             */
/*   Updated: 2023/01/26 22:52:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string megaphone(char *str)
{
	std::string res;

	for (int i = 0; str[i]; i++)
		res += toupper(str[i]);
	return res;
}

int main(int argc, char **argv)
{
	std::string output;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
		output += megaphone(argv[i]);
	std::cout << output << std::endl;
}