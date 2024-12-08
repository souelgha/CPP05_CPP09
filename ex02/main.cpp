/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:28:08 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/08 19:54:51 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

bool checkparsing(int argc, char **argv)
{
	for (int i = 1; i < argc ; ++i)
	{	
		int j = 0;
		while(argv[i][j])
		{
			if(!std::isdigit(argv[i][j]))
				return(false);
			j++;
		}			
	}
	return(true);
}
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "invalid arguments" << std::endl;
		return(1);
	}	
	if(!checkparsing(argc, argv))
	{
		std::cout<< "Invalid data" << std::endl;
			return(1);
	}
	//ajouter le int max pour le check.
	std::cout << "Before : ";
	for (int i = 0; i < argc ; ++i)
		std::cout<< argv[i]<<" ";
	std::cout<< "\n";
	
	PmergeMeVect v;
	v.sort_numbers(argc, argv);

	PmergeMeDeq dq;
	dq.sort_numbers(argc, argv);
	
	
	return(0);

}