/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:13:47 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/24 11:58:05 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include"AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test01()
{
	std::cout << "\n/***** test01 : ShrubberyCreationForm *****/\n" << std::endl;
	try
	{
		Bureaucrat sign1("Sign1",146);
		Bureaucrat DoIt1("Executor1",138);		
		ShrubberyCreationForm test("HOME"); // sign 145, exec 137
		std::cout << test;
		std::cout << sign1;
		std::cout << DoIt1 ;
		sign1.signForm(test);
		DoIt1.executeForm(test);
		sign1.IncrementGrade();
		sign1.signForm(test);
		DoIt1.executeForm(test);
		DoIt1.IncrementGrade();
		sign1.signForm(test);
		DoIt1.executeForm(test);
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
		Bureaucrat sign("Sign1",73);	
		Bureaucrat DoIt("Executor1",46);		
		RobotomyRequestForm Robot("IRobot"); // sign 72, exec 45
		std::cout << Robot;
		std::cout << sign;
		std::cout << DoIt;
		sign.signForm(Robot);
		DoIt.executeForm(Robot);
		sign.IncrementGrade();
		sign.signForm(Robot);
		DoIt.executeForm(Robot);
		DoIt.IncrementGrade();
		sign.signForm(Robot);
		DoIt.executeForm(Robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		
}
void test03()
{
	std::cout << "\n/***** test03 : PresidentialPardonForm *****/\n" << std::endl;
	try
	{
		Bureaucrat sign1("Sign1",10);
		Bureaucrat sign2("Sign2",30);		
		Bureaucrat DoIt1("Executor1",10);
		Bureaucrat DoIt2("Executor2",4);	
		PresidentialPardonForm Work("Worker"); // sign 25 exec 5
		std::cout << Work;
		std::cout << sign1;
		std::cout << sign2;
		std::cout << DoIt1;		
		std::cout << DoIt2;
		sign1.signForm(Work);
		DoIt1.executeForm(Work);
		sign2.signForm(Work);
		DoIt2.executeForm(Work);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		
}

int main()
{
	test01();
	test02();
	test03();
	return(0);
}