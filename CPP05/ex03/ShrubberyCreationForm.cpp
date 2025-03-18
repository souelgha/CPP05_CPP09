/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:25:49 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/23 17:56:17 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include<fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("unknown" , 145, 137){}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const target): AForm(target , 145, 137)
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy){}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & copy)
{
	if(this !=&copy)
		AForm::operator=(copy);
	return(*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::action() const
{
	std::string CreateFile= this->getName() +"_shrubbery";
	std::ofstream dest(CreateFile.c_str());
	if(!dest)
		std::cerr << RED << "ERROR : impossible d ecrire dans le fichier " << CreateFile << std::endl;
	dest << "     *\n";
	dest << "    / \\\n";
	dest << "   / _ \\\n";
	dest << "  /     \\\n";
	dest << " /  ___  \\\n";
	dest << "/  |||||  \\\n";
	dest.close();
}
ShrubberyCreationForm* ShrubberyCreationForm::clone(std::string target) const 
{
	return(new ShrubberyCreationForm(target));
}