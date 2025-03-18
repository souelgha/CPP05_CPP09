/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:13:19 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/31 11:25:33 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	std::cout<< "\n/***** test with random Base *****/ " << std::endl;
	Base *p;
	p = generate();
	std::cout << "Base p value  : " << p << std::endl;
	identify(p);
	identify(*p);	
	delete p;

	std::cout<< "\n/***** test with NULL and cast fail *****/ " << std::endl;
	p= NULL;
	identify(p);
	identify(*p);
	delete p;

}