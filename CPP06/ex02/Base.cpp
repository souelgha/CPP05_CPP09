/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:25:21 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/31 11:25:05 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include<stdlib.h>
#include <exception>

Base::~Base(){}

Base *generate(void)
{
	srand(time(0));

	int num =rand() % 3;
	std::cout <<"num =" << num << std::endl;
	
	if(num == 0)
		return(new A());
	else if (num == 1)
		return(new B());
	else if (num == 2)
		return(new C());
	else
		std::cout << "Bad generation" << std::endl;
	return(NULL);
}

void identify(Base *p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "ptr=> objet pointed by p is 'A'" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "ptr=> objet pointed by p is 'B'" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "ptr=> objet pointed by p is 'C'" << std::endl;
	else
		std::cout << "ptr=> no objet." << std::endl;
}
void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "ref=> objet pointed by p is 'A': " << &a << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "ref=> objet pointed by p is 'B': " << &b << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "ref=> objet pointed by p is 'C': " << &c << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	std::cout << "Ref=> No Object find."<< std::endl;
}
