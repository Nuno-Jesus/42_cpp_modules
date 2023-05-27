/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:18:20 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/27 13:37:06 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <fstream>

void usage(void)
{
	std::cout << "Usage: filename old_string new_string" << std::endl;
	exit(1);
}

std::string readContents(char *filename)
{
	std::string tmp;
	std::string content;
	std::ifstream infile;
	
	infile.open(filename, std::ios::in);
	if (infile.fail())
	{
		std::cout << "Failed to open '" << filename << "'" << std::endl;
		exit(2);
	}
	while (1)
	{
		std::getline(infile, tmp);
		content += tmp;
		if (infile.eof())
			break;
	}
	infile.close();
	return (content);
}

std::string replace(const std::string &input, 
	const std::string &oldString, const std::string &newString)
{
	size_t		newStart;
	size_t		oldStart;
	std::string result;

	oldStart = 0;
	while (1)
	{
		newStart = input.find(oldString, oldStart);
		result += input.substr(oldStart, newStart - oldStart);
		if (newStart == std::string::npos)
			break;
		result += newString;
		oldStart = newStart + oldString.length();
	}
	return (result);
}

void writeContents(char *filename, const std::string &result)
{
	std::ofstream outfile;

	outfile.open(filename, std::ios::out);
	if (outfile.fail())
	{
		std::cout << "Failed to open '" << filename << "'" << std::endl;
		exit(2);
	}
	outfile << result;
	outfile.close();
}

int main(int argc, char **argv)
{
	if (argc < 4)
		usage();
	std::string input;
	std::string oldString;
	std::string newString;
	std::string output;
	
	oldString = argv[2];
	newString = argv[3];

	input = readContents(argv[1]);
	if (oldString != "")
		output = replace(input, oldString, newString);
	else
		for (std::size_t i = 0; i < input.length(); i++)
			output += newString;
	writeContents(argv[1], output);
}
