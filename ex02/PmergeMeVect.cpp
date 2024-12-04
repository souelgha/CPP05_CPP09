/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVect.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/04 18:04:27 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

PmergeMeVect::PmergeMeVect()
{
	this->_oddVal = -1;
}
PmergeMeVect::~PmergeMeVect(){}
PmergeMeVect::PmergeMeVect(const PmergeMeVect &other)
{
	*this = other;
}
PmergeMeVect & PmergeMeVect::operator=(const PmergeMeVect &other)
{
	if(this!= &other)
		*this=other;
	return(*this);
}

void PmergeMeVect::sort_numbers( std::vector<int> &input)
{
	if(input.size() %2 != 0)
	{
		_oddVal = input.back();
		input.pop_back();
	}

	_paires = Createpaires(input);
	std::vector<int> jacobindxs = CalculJacobindx(input.size());	

	sort_pairs(_paires);
	std::cout << "paires sorted : ";
	for (size_t i=0; i < _paires.size(); i++)
		std::cout << "("<< _paires[i].first<< "," << _paires[i].second << ") ; ";
	std::cout << "\n";

	_MainChain.push_back(_paires[0].first);
	_MainChain.push_back(_paires[0].second);
	for (size_t i = 1; i <_paires.size() ; ++i)
		_MainChain.push_back(_paires[i].second);

	for (size_t i = 0; i < jacobindxs.size(); i++)
    {
        if (size_t(jacobindxs[i] - 1) >= _paires.size())
            continue;
        int index = BinarySearch(_paires[jacobindxs[i] - 1].second);
		std::vector<int>::iterator search= _MainChain.begin() + index;
		std::vector<int>::iterator pos = std::upper_bound(_MainChain.begin(),search, _paires[jacobindxs[i] - 1].first );
        _MainChain.insert(pos, _paires[jacobindxs[i] - 1].first);	
    }
	if(_oddVal != -1)
	{
		std::vector<int>::iterator pos = std::upper_bound(_MainChain.begin(),_MainChain.end(), _oddVal);
        _MainChain.insert(pos, _oddVal);
	}
	std::vector<int> :: iterator it;
	std::cout<< "Output : ";
	for (it=_MainChain.begin(); it != _MainChain.end(); ++it)
	std::cout << *it <<" ";
	std::cout <<"\n";
}
std::vector<std::pair<int, int> > PmergeMeVect::Createpaires(std::vector<int> &input)
{
	std::vector<std::pair<int, int> > paires;
	for(size_t i=0; i+1 < input.size(); i+=2)
	{
		if(input[i]> input[i+1])
			std::swap(input[i], input[i+1]);		
		paires.push_back(std::make_pair(input[i], input[i+1]));
	}
	return paires;
}
void PmergeMeVect::sort_pairs(std::vector<std::pair<int, int> >  &pairs) 
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

void PmergeMeVect::MergeSorted( std::vector<std::pair<int, int> >  &leftH, std::vector<std::pair<int, int> >  &rightH, std::vector<std::pair<int, int> > &pairs)
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

std::vector<int> PmergeMeVect::CalculJacobindx(size_t lenght) 
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

int PmergeMeVect::BinarySearch(int target)
{
	int low = 0;
	int high = _MainChain.size() - 1;
	
	while(low <= high)
	{
		int middle = low + (high - low)/2;
		if(target == _MainChain[middle])
			return(middle);
		if(target < _MainChain[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}
	return(-1);	
}