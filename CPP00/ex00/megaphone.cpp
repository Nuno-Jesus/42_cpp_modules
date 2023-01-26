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

using std::cout;
using std::string;
using std::endl;

string megaphone(char *str)
{
	string res;

	for (int i = 0; str[i]; i++)
		res += toupper(str[i]);
	return res;
}

int main(int argc, char **argv)
{
	string output;

	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return 0;
	}
	
	for (int i = 1; i < argc; i++)
		output += megaphone(argv[i]);
	cout << output << endl;
}