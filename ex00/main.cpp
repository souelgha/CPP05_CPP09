/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:58:43 by sonia             #+#    #+#             */
/*   Updated: 2024/11/14 18:16:43 by sonouelg         ###   ########.fr       */
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

	parsInput(argv[1]);
	return(0);
}