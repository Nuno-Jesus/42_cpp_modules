/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:05:40 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 15:05:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : \
	AForm("Shrubbery Creation Form", 145, 137), target("Someone")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : \
	AForm("Shrubbery Creation Form", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : \
	AForm(copy), target(copy.target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& right)
{
	if (this == &right)
		return (*this);
	this->setIsSigned(right.hasBeenSigned());
	return (*this);
}

void ShrubberyCreationForm::execute(void) const
{
	std::ofstream outfile;

	outfile.open((this->target + "_shrubbery").c_str(), std::ios::out);
	if (outfile.fail())
		throw std::runtime_error("Could not open " + this->target + "_shrubbery");
	outfile << "                                              .    " << std::endl;
	outfile << "                                   .         ;     " << std::endl;
	outfile << "      .              .              ;%     ;;      " << std::endl;
	outfile << "        ,           ,                :;%  %;       " << std::endl;
	outfile << "         :         ;                   :;%;'     .," << std::endl;
	outfile << ",.        %;     %;            ;        %;'    ,;  " << std::endl;
	outfile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'   " << std::endl;
	outfile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'    " << std::endl;
	outfile << "    ;%;      %;        ;%;        % ;%;  ,%;'      " << std::endl;
	outfile << "     `%;.     ;%;     %;'         `;%%;.%;'        " << std::endl;
	outfile << "      `:;%.    ;%%. %@;        %; ;@%;%'           " << std::endl;
	outfile << "         `:%;.  :;bd%;          %;@%;'             " << std::endl;
	outfile << "           `@%:.  :;%.         ;@@%;'              " << std::endl;
	outfile << "             `@%.  `;@%.      ;@@%;                " << std::endl;
	outfile << "               `@%%. `@%%    ;@@%;                 " << std::endl;
	outfile << "                 ;@%. :@%%  %@@%;                  " << std::endl;
	outfile << "                   %@bd%%%bd%%:;                   " << std::endl;
	outfile << "                     #@%%%%%:;;                    " << std::endl;
	outfile << "                     %@@%%%::;                     " << std::endl;
	outfile << "                     %@@@%(o);  . '                " << std::endl;
	outfile << "                     %@@@o%;:(.,'                  " << std::endl;
	outfile << "                 `.. %@@@o%::;                     " << std::endl;
	outfile << "                    `)@@@o%::;                     " << std::endl;
	outfile << "                     %@@(o)::;                     " << std::endl;
	outfile << "                    .%@@@@%::;                     " << std::endl;
	outfile << "                    ;%@@@@%::;.                    " << std::endl;
	outfile << "                   ;%@@@@%%:;;;.                   " << std::endl;
	outfile << "               ...;%@@@@@%%:;;;;,..                " << std::endl;
	outfile << std::endl;
}
