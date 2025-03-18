/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:22:01 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/06 13:40:18 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Array.hpp"

void test01()
{
	std::cout<<CYAN << "\n/************ int Array ***********/\n"<< WHITE <<std::endl;
	int * a = new int();//init valeur par defaut 
	std::cout <<"*a= " << *a << std::endl;

	Array<int> intArray2; //empty
	Array<int> intArray(3);
	std::cout<<"/***** before ******/"<< std::endl;
	std::cout << intArray<< std::endl;
	std::cout << intArray2<< std::endl;
	intArray[0] = 20;
	intArray[1] = 10;
	intArray[2] = 120;
	std::cout<<"/***** after ******/"<< std::endl;
	std::cout << intArray<< std::endl;
	std::cout<<"/***** Out of range ******/"<< std::endl;
	try
	{
		intArray[-1] = 2;	
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		intArray[3] = 40;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete a;
}
void test02()
{
	std::cout<<CYAN << "\n/************ Char Array ***********/\n"<< WHITE<<std::endl;
	Array<char> charArray(3);
	std::cout<<"/***** before ******/"<< std::endl;
	std::cout << charArray<< std::endl;
	charArray[0] = 't';
	charArray[1] = 'f';
	charArray[2] = 'r';
	std::cout<<"/***** after ******/"<< std::endl;
	std::cout << charArray << std::endl;

}
void test03()
{
	std::cout<<CYAN << "\n/************ String Array ***********/\n" << WHITE << std::endl;
	Array<std::string> charArray(3);
	std::cout<<"/***** before ******/"<< std::endl;
	std::cout << charArray<< std::endl;
	charArray[0] = "toto";
	charArray[1] = "tata";
	charArray[2] = "titi";
	std::cout<<"/***** after ******/"<< std::endl;
	std::cout << charArray<< std::endl;
}

void test04()
{
	std::cout<< CYAN<< "\n/************* test assignment ************/\n"<< WHITE <<std::endl;
	Array<int> intArray(3);
	std::cout<<"/***** before ******/"<< std::endl;
	std::cout << intArray<< std::endl;
	intArray[0] = 20;
	intArray[1] = 10;
	intArray[2] = 120;
	std::cout<<"/***** after ******/"<< std::endl;
	std::cout << intArray<< std::endl;

	Array<int> intArray2;
	std::cout<<"/***** Array2 before assignment******/"<< std::endl;
	std::cout << intArray<< std::endl;
	intArray2 = intArray;
	std::cout<<"/***** Array2 after assignement ******/"<< std::endl;
	std::cout << intArray2<< std::endl;
	intArray[0] = 39;
	intArray2[1] = 59;
	std::cout<<"/***** after modif value ******/"<< std::endl;
	std::cout << intArray<< std::endl;
	std::cout << intArray2<< std::endl;
}
void test05()
{
	std::cout << CYAN <<"\n/************** test copy ************/\n"<< WHITE << std::endl;
	Array<int> intArray(3);
	std::cout<<"/***** before ******/"<< std::endl;
	std::cout << intArray<< std::endl;
	intArray[0] = 20;
	intArray[1] = 10;
	intArray[2] = 120;
	std::cout<<"/***** after ******/"<< std::endl;
	std::cout << intArray<< std::endl;
	
	Array<int> intArray2(intArray); 
	std::cout<<"/***** Array2 after copy ******/"<< std::endl;
	std::cout << intArray<< std::endl;
	std::cout << intArray2<< std::endl;
	intArray[0] = 39;
	intArray2[1] = 59;
	std::cout<<"/***** after modif value ******/"<< std::endl;
	std::cout << intArray<< std::endl;
	std::cout << intArray2<< std::endl;
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