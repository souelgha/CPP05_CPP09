/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:56:58 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/16 18:13:39 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


bool parsingArg(char *str)
{
	int i= 0;
	while(str[i])
	{
		if(str[i] =='(' || str[i] == ')' || std::isalpha(str[i]))
		{
			std::cerr << "Error" << std::endl;
			return false;
		}
		if (str[i])
		{
			/* code */
		}
		
	}
}
int main(int argc, char **argv)
{
	
	if(argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return(1);
	}
	return(0);
}