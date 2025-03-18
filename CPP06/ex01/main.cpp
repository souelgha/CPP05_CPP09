/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:08:46 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/31 11:15:13 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"

int main()
{
	Data test;
	test.data1 = 23;
	test.data2 = -12;
	
	std::cout << "\ntest: " << &test << std::endl;
	std::cout << "test data1 : " << test.data1 << std::endl;
	std::cout << "test data2 : " << test.data2 << std::endl;

	uintptr_t num1 = Serializer::serialize(&test);
	std::cout << "\nnum1: " << num1 << std::endl;	

	Data *toto = Serializer::deserialize(num1);
	std::cout << "\ntoto: " << toto<< std::endl;
	std::cout << "toto data1 : " << toto->data1 << std::endl;
	std::cout << "toto data2 : " << toto->data2 << std::endl;

	return(0);

}