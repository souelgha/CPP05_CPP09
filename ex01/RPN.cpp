/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:57:11 by sonia             #+#    #+#             */
/*   Updated: 2024/11/16 09:42:46 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN &other){}
RPN & RPN::operator=(const RPN& other){}
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
void RPN::resultRPN(std::string str) const
{
	// _pile.push();
}