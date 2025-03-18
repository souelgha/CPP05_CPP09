/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:05:50 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/24 12:24:50 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	this->form[0]= new ShrubberyCreationForm();
	this->form[1]= new RobotomyRequestForm();
	this->form[2]= new PresidentialPardonForm();
}
Intern::~Intern()
{
	for(int i = 0; i < 3; ++i)
		delete form[i];
}
Intern::Intern(const Intern& copy)
{
	(void)copy;
	this->form[0]= new ShrubberyCreationForm();
	this->form[1]= new RobotomyRequestForm();
	this->form[2]= new PresidentialPardonForm();

}
Intern& Intern::operator=(const Intern& copy)
{
	(void)copy;
	return(*this);
}
const char* Intern::FormDoesntExist::what() const throw() 
{
    return "The requested form doesn't exist.";
}
AForm* Intern::makeForm(std::string FormName, std::string target)
{
	try
	{
		std::string TabName[3]=	{"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
		
		for(int i= 0; i < 3; ++i)
			{
				if(TabName[i] == FormName)
					{
						std::cout<<"Intern creates " << target << std::endl;
						return(this->form[i]->clone(target));
					}
			}
		throw Intern::FormDoesntExist();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << WHITE<< std::endl;
	}
	return(NULL); 
}