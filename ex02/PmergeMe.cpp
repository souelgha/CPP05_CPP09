/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/21 15:29:19 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

std::vector<std::pair<int, int> > Createpaires(std::vector<int> &input)
{
	std::vector<std::pair<int, int> > paires;

	for(size_t i=0; i+1 < input.size(); i+=2)
	{
		if(input[i]< input[i+1])
			paires.push_back(std::make_pair(input[i], input[i+1]));
		else
			paires.push_back(std::make_pair(input[i+1], input[i]));
	}
	return paires;
}
