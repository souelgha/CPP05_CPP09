/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:58:43 by sonia             #+#    #+#             */
/*   Updated: 2024/11/15 16:32:23 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	
	if(argc != 2)
	{
		std::cerr << "Error:couldn't open file" << std::endl;
		return(1);
	}
	BitcoinExchange b;	
	b.parsExchange();
	std::cout << "---------------------------------------" << std::endl;
	b.parsInput(argv[1]);
	std::cout << "---------------------------------------" << std::endl;

	return(0);
}