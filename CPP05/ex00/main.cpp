/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:39:48 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/24 10:05:18 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test01()
{
	std::cout << "/***** test01: grade = 130 *****/" << std::endl;
	try
	{
		Bureaucrat T("Tom",130);
		std::cout << T << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << RED<< e.what() << WHITE << std::endl;

	}
	std::cout<< "\n";
}

void test02()
{
	std::cout << "/***** test02: High grade = 0 *****/" << std::endl;
	try
	{
		Bureaucrat T("Tom",0);
		std::cout << T << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << RED<< e.what() << WHITE << std::endl;

	}
	std::cout<< "\n";
}
void test03()
{
	std::cout << "/***** test03: low grade = 160 *****/" << std::endl;
	try
	{
		Bureaucrat T("Tom",160);
		std::cout << T << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << RED<< e.what() << WHITE << std::endl;

	}
	std::cout<< "\n";
}
void test04()
{
	std::cout << "/***** test04: grade = 5 increment to grade = 4 *****/" << std::endl;
	try
	{
		Bureaucrat T("Tom",5);
		std::cout << T << std::endl;
		T.IncrementGrade();
		std::cout << T << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << RED<< e.what() << WHITE << std::endl;

	}
	std::cout<< "\n";
}
void test05()
{
	std::cout << "/***** test05: grade = 5 decrement to grade = 6 *****/" << std::endl;
	try
	{
		Bureaucrat T("Tom",5);
		std::cout << T << std::endl;
		T.DecrementGrade();
		std::cout << T << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << RED<< e.what() << WHITE << std::endl;

	}
	std::cout<< "\n";
}
int main()
{

	test01();
	test02();
	test03();
	test04();
	test05();

	return(0);
}