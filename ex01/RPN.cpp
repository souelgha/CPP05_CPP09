/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:57:11 by sonia             #+#    #+#             */
/*   Updated: 2024/11/18 13:00:27 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN &other)
{
	this->_pile = other._pile;
}
RPN & RPN::operator=(const RPN& other)
{
	if(this != &other)
		this->_pile = other._pile;
	return(*this);
}
int RPN::multiply(const int &a, const int &b)
{
	return(a * b);
}
int RPN::divise(const int &a, const int &b)
{
	if(b == 0)
		throw std::invalid_argument("0 is not acceptable for division");
	return(a / b);
}
int RPN::add(const int &a, const int &b)
{
	return( a + b);
}
int RPN::soustract(const int &a, const int &b)
{
	return(a - b);
}
void RPN::resultRPN(std::string str)
{
	std::istringstream ss(str);
	std::string token;
	
	while(ss >> token)
	{
		if ((isdigit(token[0])))
			_pile.push(std::atoi(token.c_str()));
		else
		{
			int b = _pile.top(); 
			_pile.pop();
			int a = _pile.top();
			_pile.pop();
			int result;
			if(token == "*" )
				result = multiply(a,b);
			else if(token == "/" )
				result = divise(a,b);
			else if(token == "+" )
				result = add(a,b);
			else if(token == "-" )
				result = soustract(a,b);			
			_pile.push(result);
		}
	}
	if(_pile.size() != 1)
		throw std::invalid_argument("invalid stack size.");
	std::cout<< _pile.top()<< std::endl;
}