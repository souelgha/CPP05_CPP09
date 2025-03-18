/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:54:01 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/07 10:45:38 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void test01()
{
	std::list<int> lst;
	lst.push_back(6);
	lst.push_back(8);
	lst.push_back(23);
	lst.push_back(8);
	lst.push_back(60);
		
	try
	{
		std::list<int>::const_iterator it = easyfind(lst, 60);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "list :" << e.what() << '\n';
	}
}

void test02()
{
	std::vector<int> numbers;
	numbers.push_back(2);
	numbers.push_back(5);
	numbers.push_back(123);
	numbers.push_back(5);
	numbers.push_back(40);
	
	try
	{
		std::vector<int>::const_iterator it = easyfind(numbers, 40);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "vector :" << e.what() << '\n';
	}	
}

int main ()
{
	test01();
	test02();
}