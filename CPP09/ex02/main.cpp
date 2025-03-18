/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:28:08 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/09 16:25:34 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

bool checkparsing(int argc, char **argv)
{
	long int nb;
	int n = 2147483647;
	for (int i = 1; i < argc ; ++i)
	{	
		int j = 0;
		if(argv[i][j] == '+')
			j++;
		while(argv[i][j])
		{
			if(!std::isdigit(argv[i][j]))
				return(false);
			j++;
		}
		nb = std::atol(argv[i]);
		if(nb > n)
			return(false);
	}
	return(true);
}
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "invalid arguments" << std::endl;
		return(1);
	}	
	if(!checkparsing(argc, argv))
	{
		std::cerr<< "Invalid data" << std::endl;
		return(1);
	}

	std::cout << "Before : ";
	for (int i = 1; i < argc ; ++i)
		std::cout<< argv[i]<<" ";
	std::cout<< "\n";
	
	PmergeMe v;
	v.sort_numbers_V(argc, argv);
	v.printV();

	PmergeMe dq;
	dq.sort_numbers_Q(argc, argv);
	// dq.printQ();

	v.printVTime();
	dq.printQTime();
	
	
	return(0);

}