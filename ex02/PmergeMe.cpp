/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/02 18:34:52 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

std::vector<std::pair<int, int> > Createpaires(std::vector<int> &input)
{
	std::vector<std::pair<int, int> > paires;
	if(input.size()%2 != 0)
	{
		// int value = input.back();
		input.pop_back();
	}

	for(size_t i=0; i+1 < input.size(); i+=2)
	{
		if(input[i]< input[i+1])
			std::swap(input[i], input[i+1]);		
		paires.push_back(std::make_pair(input[i], input[i+1]));
	}
	return paires;
}
void sort_pairs(std::vector<std::pair<int, int> >  &pairs) 
{
    if (pairs.size() <= 1)
        return; 
	
    // divise le vector de paires en 2 moities
    size_t middle = pairs.size() / 2;
    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + middle);
	std::cout << "pairs left : ";
	for (size_t i= 0; i < middle; ++i)
		std::cout << "("<< pairs[i].first<< "," << pairs[i].second << ") ; ";
	std::cout<< "\n";
  	std::vector<std::pair<int, int> > right(pairs.begin() + middle, pairs.end());
	std::cout << "pairs right: ";
	for (size_t i= middle; i < pairs.size(); ++i)
		std::cout << "("<< pairs[i].first<< "," << pairs[i].second << ") ; ";
	std::cout<< "\n";

	
    // trie recursif des 2 moities
    sort_pairs(left);
    sort_pairs(right);
std::cout << "sortie: ";
   // Merge des 2 moities triees
    MergeSorted(left, right, pairs);
	// std::cout << "MergeSorted: ";
	// for (size_t i= 0; i < pairs.size(); ++i)
	// 	std::cout << "("<< pairs[i].first<< "," << pairs[i].second << ") ; ";
	// std::cout<< "\n";
}

void MergeSorted( std::vector<std::pair<int, int> >  leftH, std::vector<std::pair<int, int> >  rightH, std::vector<std::pair<int, int> > &pairs)
{
    size_t indxL = 0;
    size_t indxR = 0;
    size_t indx = 0;

    while (indxL < leftH.size() && indxR < rightH.size()) 
	{
		if (leftH[indxL].first < rightH[indxR].first)
			pairs[indx++] = leftH[indxL++];
		else
			pairs[indx++] = rightH[indxR++];
    }
	while(indxL < leftH.size())
		pairs[indx++] = leftH[indxL++];
	while(indxR < rightH.size())
		pairs[indx++] = rightH[indxR];

}
void Createpair(std::vector<int> &input)
{
	std::vector<int> BigElements;
	std::vector<int> SmallElements;
	
	for (size_t i = 0; i + 1 <input.size() ; i+=2)
	{
		if(input[i] > input[i+1])
			std::swap(input[i], input[i+1]);
		BigElements.push_back(input[i+1]);
		SmallElements.push_back(input[i]);
				
	} 
	std::vector<int> :: iterator i;
	std::cout<< "Big : ";
	for (i=BigElements.begin(); i != BigElements.end(); ++i)
		std::cout << *i <<" ";
	std::cout<< "\nSmall : ";
	for (i=SmallElements.begin(); i != SmallElements.end(); ++i)
		std::cout << *i <<" ";
		
	std::cout<< "\n";
}