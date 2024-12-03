/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/03 18:29:35 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

void sort_numbers( std::vector<int> &input)
{
	std::vector< std::pair< int, int > > paires = Createpaires(input);
	// generate index Jacobsthal;

	sort_pairs(paires);

	std::vector<int> MainChain;
	MainChain.push_back(paires[0].first);
	MainChain.push_back(paires[0].second);
	for (size_t i = 1; i <paires.size() ; ++i)
	{
		MainChain.push_back(paires[i].second);
	}
	std::vector<int> :: iterator i;
	std::cout<< "Big : ";
	for (i=MainChain.begin(); i != MainChain.end(); ++i)
		std::cout << *i <<" ";
	
	
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
	std::cout << "MS pairs: ";
	for (size_t i=0; i < pairs.size(); i++)
		std::cout << "("<< pairs[i].first<< "," << pairs[i].second << ") ; ";
	std::cout << "\n";

}

// std::vector<int> generate_indexes(size_t size) 
// {
//     std::vector<int> indexes;
//     int jacobsthalArray[size + 1];

//     jacobsthalArray[0] = 0;
//     jacobsthalArray[1] = 1;
//     int lastJNum = 2;

//     for (size_t i = 2; indexes.size() < size; i++)
//     {
//         jacobsthalArray[i] = jacobsthalArray[i - 1] + 2 * jacobsthalArray[i - 2];
//         if(i != 2)
//         {
//             indexes.push_back(jacobsthalArray[i]);
//         }

//         // Push back the indexes between the last Jacobsthal number and the current one
//         for (int j = jacobsthalArray[i] - 1; j > lastJNum; j--)
//             indexes.push_back(j);

//         // Update the last Jacobsthal number
//         lastJNum = jacobsthalArray[i];
//     }
//     return (indexes);
// }

// int BinarySearch(int target)
// {
// 	int low = 0;
// 	int high = MainChain.size() - 1;
	
// 	while(low <= high)
// 	{
// 		int middle = low + (high - low)/2;
// 		if(target == MainChain[middle])
// 			return(middle);
// 		if(target < MainChain[middle])
// 			high = middle - 1;
// 		else
// 			low = middle + 1;
// 	}
// 	return(-1);	
// }