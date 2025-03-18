/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:56:58 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/18 13:01:32 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


bool parsingArg(char *str)
{
	int i= 0;
	if(!std::isdigit(str[0]) || !std::isdigit(str[2]))
		return false;
	while(str[i])
	{
		if ((!std::isdigit(str[i])) && str[i] !='*' && str[i] != '/' && str[i] !='-' && str[i] !='+' && str[i] != ' ')
			return false;
		if (i % 2 == 1 && str[i] != ' ')
			return false;		
		i++;		
	}
	return true;
}
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return(1);
	}
	if(!parsingArg(argv[1]))
	{
		std::cerr << "Error" << std::endl;
		return(1);
	}
	RPN r;
	try
	{
		r.resultRPN(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return(0);
}