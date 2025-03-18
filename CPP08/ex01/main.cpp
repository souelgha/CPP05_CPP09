/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:54:01 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/14 11:29:28 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include<ctime>


void test01()
{
	Span numbers(12);
	std::vector<int> list;
	srand(time(0));

	try
	{
		for(size_t i =0; i<10; i++)
			numbers.addNumber(rand() % 100);
		numbers.display();
	std::cout<< "----- short and long -----" << std::endl;
	std::cout<< numbers.shortestSpan() << std::endl;
	std::cout<< numbers.longestSpan() << std::endl;
	std::cout<< "----- add data with range -----" << std::endl;
	list.push_back(rand() % 100);
	list.push_back(rand() % 100);
	// list.push_back(50);
	// list.push_back(1);
	numbers.RangeIt(list.begin(), list.end());
	numbers.display();
	std::cout<< "----- short and long -----" << std::endl;
	std::cout<< numbers.shortestSpan() << std::endl;
	std::cout<< numbers.longestSpan() << std::endl;
 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main ()
{
	test01();
	return(0);
}