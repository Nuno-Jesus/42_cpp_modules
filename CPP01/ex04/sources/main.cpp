/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:18:20 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/20 16:02:42 by ncarvalh         ###   ########.fr       */
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
	char next;
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
		infile.get(next);
		if (infile.eof())
			break;
		content += next;
	}
	infile.close();
	return (content);
}

std::string replace(const std::string &contents, 
	const std::string &oldString, const std::string &newString)
{
	size_t		newStart;
	size_t		oldStart;
	std::string result;

	oldStart = 0;
	while (1)
	{
		newStart = contents.find(oldString, oldStart);
		std::cout << "Old Start: " << oldStart << std::endl;
		std::cout << "New Start: " << newStart << std::endl;
		result += contents.substr(oldStart, newStart - oldStart);
		std::cout << "String so far " << result << std::endl;
		if (newStart == std::string::npos)
			break;
		result += newString;
		std::cout << "String so far " << result << std::endl;
		oldStart = newStart + oldString.length();
	}
	return (result);
}

void writeContents(char *filename, const std::string &contents)
{
	std::ofstream outfile;

	outfile.open(filename, std::ios::out);
	if (outfile.fail())
	{
		std::cout << "Failed to open '" << filename << "'" << std::endl;
		exit(2);
	}
	outfile << contents;
	outfile.close();
}



int main(int argc, char **argv)
{
	if (argc < 4)
		usage();
	std::string contents;
	std::string oldString;
	std::string newString;
	
	oldString = argv[2];
	newString = argv[3];

	contents = readContents(argv[1]);
	contents = replace(contents, oldString, newString);
	writeContents(argv[1], contents);
}
