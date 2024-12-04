/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeq.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/04 17:51:39 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

void sort_numbers( std::vector<int> &input)
{
	if(input.size()%2 != 0)
	std::vector< std::pair< int, int > > paires = Createpaires(input);
	std::vector<int> jacobindxs = CalculJacobindx(input.size());	

	sort_pairs(paires);
	std::cout << "paires sorted : ";
	for (size_t i=0; i < paires.size(); i++)
		std::cout << "("<< paires[i].first<< "," << paires[i].second << ") ; ";
	std::cout << "\n";

	std::vector<int> MainChain;
	MainChain.push_back(paires[0].first);
	MainChain.push_back(paires[0].second);
	for (size_t i = 1; i <paires.size() ; ++i)
		MainChain.push_back(paires[i].second);

	for (size_t i = 0; i < jacobindxs.size(); i++)
    {
        if (size_t(jacobindxs[i] - 1) >= paires.size())
            continue;
        int index = BinarySearch(paires[jacobindxs[i] - 1].second, MainChain);
		std::vector<int>::iterator search= MainChain.begin() + index;
		std::vector<int>::iterator pos = std::upper_bound(MainChain.begin(),search, paires[jacobindxs[i] - 1].first );
        MainChain.insert(pos, paires[jacobindxs[i] - 1].first);

	
    }
	std::vector<int> :: iterator it;
	std::cout<< "Output : ";
	for (it=MainChain.begin(); it != MainChain.end(); ++it)
	std::cout << *it <<" ";
	std::cout <<"\n";
}
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
		if(input[i]> input[i+1])
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
  	std::vector<std::pair<int, int> > right(pairs.begin() + middle, pairs.end());
	
    // trie recursif des 2 moities
    sort_pairs(left);
    sort_pairs(right);

   // Merge des 2 moities triees
    MergeSorted(left, right, pairs);
}

void MergeSorted( std::vector<std::pair<int, int> >  &leftH, std::vector<std::pair<int, int> >  &rightH, std::vector<std::pair<int, int> > &pairs)
{
    size_t indxL = 0;
    size_t indxR = 0;
    size_t indx = 0;

    while (indxL < leftH.size() && indxR < rightH.size()) 
	{
		if (leftH[indxL].second < rightH[indxR].second)
			pairs[indx++] = leftH[indxL++];
		else
			pairs[indx++] = rightH[indxR++];
    }
	while(indxL < leftH.size())
		pairs[indx++] = leftH[indxL++];
	while(indxR < rightH.size())
		pairs[indx++] = rightH[indxR++];
}

std::vector<int> CalculJacobindx(size_t lenght) 
{
    std::vector<int> jacobindx;
    int jacobsthalArray[lenght];

    jacobsthalArray[0] = 0;
    jacobsthalArray[1] = 1;
    int lastJNum = 2;

    for (size_t i = 2; jacobindx.size() < lenght; i++)
    {
        jacobsthalArray[i] = jacobsthalArray[i - 1] + 2 * jacobsthalArray[i - 2];
        if(i != 2)
            jacobindx.push_back(jacobsthalArray[i]);

        // ajout des index intermedaires dans le vector 
        for (int j = jacobsthalArray[i] - 1; j > lastJNum; j--)
            jacobindx.push_back(j);
        lastJNum = jacobsthalArray[i];
    }
	std::vector<int> :: iterator i;
	std::cout<< "Jacobsthal : ";
	for (i=jacobindx.begin(); i != jacobindx.end(); ++i)
		std::cout << *i <<" ";
	std::cout <<"\n";
    return (jacobindx);
}

int BinarySearch(int target, std::vector<int> &MainChain)
{
	int low = 0;
	int high = MainChain.size() - 1;
	
	while(low <= high)
	{
		int middle = low + (high - low)/2;
		if(target == MainChain[middle])
			return(middle);
		if(target < MainChain[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}
	return(-1);	
}