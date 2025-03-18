/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:13:47 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/24 12:30:54 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include"AForm.hpp"
#include "ShrubberyCreationForm.hpp" // sign 145, exec 137
#include "RobotomyRequestForm.hpp" // sign 72, exec 45
#include "PresidentialPardonForm.hpp" // sign 25 exec 5
#include "Intern.hpp"

void test01()
{
	std::cout << "\n/***** test01 : PresidentialPardonForm *****/\n" << std::endl;
	try
	{
		Bureaucrat sign1("Sign1",20);
		Bureaucrat DoIt1("Executor1",3);	
		Intern someRandomIntern;
		AForm* Help;
		Help = someRandomIntern.makeForm("PresidentialPardonForm", "Help");
		std::cout << *Help;
		std::cout << sign1;
		std::cout << DoIt1;
		sign1.signForm(*Help);
		DoIt1.executeForm(*Help);

		delete Help;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void test02()
{
	std::cout << "\n/***** test02 : RobotomyRequestForm *****/\n" << std::endl;
	
	try
	{
		Bureaucrat sign("Sign2",70);	
		Bureaucrat DoIt("Executor2",6);		
		Intern someRandomIntern;
		AForm* Robot;
		Robot = someRandomIntern.makeForm("RobotomyRequestForm", "Robot");;
		std::cout << *Robot;
		std::cout << sign;
		std::cout << DoIt;
		sign.signForm(*Robot);
		DoIt.executeForm(*Robot);

		delete Robot;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		
}
void test03()
{
	std::cout << "\n/***** test03 : ShrubberyCreationForm *****/\n" << std::endl;
	try
	{
		Bureaucrat sign1("Sign1",148);	
		Bureaucrat DoIt1("Executor1",30);
		Intern someRandomIntern;
		AForm* Bender;
		Bender = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		std::cout << *Bender;
		std::cout << sign1;
		std::cout << DoIt1;	
		sign1.signForm(*Bender);
		DoIt1.executeForm(*Bender);
		
		delete Bender;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		
}
void test04()
{	
	std::cout << "\n/***** test04 : Intern tasks *****/\n" << std::endl;

	Intern someRandomIntern;
	AForm *doc1, *doc2, *doc3, *doc4 ;
	doc1 = someRandomIntern.makeForm("PresidentialPardonForm", "Help");
	doc2 = someRandomIntern.makeForm("RobotomyRequest", "toto");
	doc3 = someRandomIntern.makeForm("ShrubberyCreationForm", "Shrubbery");
	doc4 = someRandomIntern.makeForm("RobotomyRequestForm", "Robot");
	
	delete doc1;
	delete doc2;
	delete doc3;
	delete doc4;
		
}
int main()
{
	test01();
	test02();
	test03();
	test04();
	return(0);
}