/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:34:37 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/06 12:04:07 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "iter.hpp"

int main()
{
	char tab1[]={'a', 'b', 'c'};
	int tab2[]={1, 2, 3};
	double tab3[]= {1.6, 2.9, 3.1};
	std::string tab4[]={"toto", "titi", "tata"};	

	std::cout<< "\n/******** addtwo char  ********/"<< std::endl;
	::iter(tab1, 3, addtwo<char>);
	for(size_t i = 0; i< 3; ++i)
		std::cout<< "tab["<<i<<"]="<< tab1[i] << std::endl;	
	
	std::cout<< "\n/******** addtwo int  *******/"<< std::endl;
	::iter(tab2, 3, addtwo<int>);
	for(size_t i = 0; i< 3; ++i)
		std::cout<< "tab["<<i<<"]="<< tab2[i] << std::endl;
	
	std::cout<< "\n/******* addtwo double *******/"<< std::endl;
	::iter(tab3, 3, addtwo<double>);
	for(size_t i = 0; i< 3; ++i)
		std::cout<< "tab["<<i<<"]="<< tab3[i] << std::endl;	
	
	std::cout<< "\n/***** print string *****/"<< std::endl;	
	::iter(tab4, 3, printTab<std::string>);
	std::cout<< "\n/***** print int *****/"<< std::endl;	
	::iter(tab2, 3, printTab<int>);
}