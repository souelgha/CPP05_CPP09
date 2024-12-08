/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeq.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/08 20:02:46 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

PmergeMeDeq::PmergeMeDeq()
{
	this->_oddVal = -1;
	this->_time = 0;
	this->_size = 0;
}

PmergeMeDeq::~PmergeMeDeq(){}
PmergeMeDeq::PmergeMeDeq(const PmergeMeDeq &other):PmergeMe(other)
{
	*this = other;
}
PmergeMeDeq & PmergeMeDeq::operator=(const PmergeMeDeq &other)
{
	if(this!= &other)
		*this = other;
	return(*this);
}
void PmergeMeDeq::ft_stoi( int argc, char **data)
{
	for (int i = 1; i < argc ; ++i)
	{
		std::istringstream ss(data[i]);
		int value;
		ss >> value;
		_input.push_back(value);
	}
	_size = _input.size();
/*	std::cout << "Before : ";
	for (size_t i = 0; i < _input.size() ; ++i)
		std::cout<< _input[i]<<" ";
	std::cout<<"\n";*/
}

void PmergeMeDeq::sort_numbers( int argc, char **data)
{
	std::clock_t startTime = std::clock();
	ft_stoi(argc, data);
	if(_input.size() %2 != 0)
	{
		_oddVal = _input.back();
		_input.pop_back();
	}

	_paires = Createpaires(_input);
	std::deque<int> jacobindxs = CalculJacobindx(_input.size());
	if(_paires.size() == 0)
	{
		_MainChain.push_back(_oddVal);
		_time = 1000.0 * (std::clock() - startTime) / (double) CLOCKS_PER_SEC;
		printDeq();
		return;
	}

	sort_pairs(_paires);
	/*std::cout << "paires sorted : ";
	for (size_t i=0; i < _paires.size(); i++)
		std::cout << "("<< _paires[i].first<< "," << _paires[i].second << ") ; ";
	std::cout << "\n";*/

	_MainChain.push_back(_paires[0].first);
	_MainChain.push_back(_paires[0].second);
	for (size_t i = 1; i <_paires.size() ; ++i)
		_MainChain.push_back(_paires[i].second);

	for (size_t i = 0; i < jacobindxs.size(); i++)
    {
        if (size_t(jacobindxs[i] - 1) >= _paires.size())
            continue;
        int index = BinarySearch(_paires[jacobindxs[i] - 1].second);
		std::deque<int>::iterator search= _MainChain.begin() + index;
		std::deque<int>::iterator pos = std::upper_bound(_MainChain.begin(),search, _paires[jacobindxs[i] - 1].first );
        _MainChain.insert(pos, _paires[jacobindxs[i] - 1].first);	
    }
	if(_oddVal != -1)
	{
		std::deque<int>::iterator pos = std::upper_bound(_MainChain.begin(),_MainChain.end(), _oddVal);
        _MainChain.insert(pos, _oddVal);
	}
	_time = 1000.0 * (std::clock() - startTime) / (double) CLOCKS_PER_SEC;
	printDeq();
}
std::deque<std::pair<int, int> > PmergeMeDeq::Createpaires(std::deque<int> &input)
{
	std::deque<std::pair<int, int> > paires;
	for(size_t i=0; i+1 < input.size(); i+=2)
	{
		if(input[i]> input[i+1])
			std::swap(input[i], input[i+1]);		
		paires.push_back(std::make_pair(input[i], input[i+1]));
	}
	return paires;
}
void PmergeMeDeq::sort_pairs(std::deque<std::pair<int, int> >  &pairs) 
{
    if (pairs.size() <= 1)
        return; 
	
    // divise le deque de paires en 2 moities
    size_t middle = pairs.size() / 2;
    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + middle);	
  	std::deque<std::pair<int, int> > right(pairs.begin() + middle, pairs.end());
	
    // trie recursif des 2 moities
    sort_pairs(left);
    sort_pairs(right);

   // Merge des 2 moities triees
    MergeSorted(left, right, pairs);
}

void PmergeMeDeq::MergeSorted( std::deque<std::pair<int, int> >  &leftH, std::deque<std::pair<int, int> >  &rightH, std::deque<std::pair<int, int> > &pairs)
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

std::deque<int> PmergeMeDeq::CalculJacobindx(size_t lenght) 
{
    std::deque<int> jacobindx;
    int jacobsthalArray[lenght];

    jacobsthalArray[0] = 0;
    jacobsthalArray[1] = 1;
    int lastJNum = 2;

    for (size_t i = 2; jacobindx.size() < lenght; i++)
    {
        jacobsthalArray[i] = jacobsthalArray[i - 1] + 2 * jacobsthalArray[i - 2];
        if(i != 2)
            jacobindx.push_back(jacobsthalArray[i]);

        // ajout des index intermedaires dans le deque 
        for (int j = jacobsthalArray[i] - 1; j > lastJNum; j--)
            jacobindx.push_back(j);
        lastJNum = jacobsthalArray[i];
    }
/*	std::deque<int> :: iterator i;
	std::cout<< "Jacobsthal : ";
	for (i=jacobindx.begin(); i != jacobindx.end(); ++i)
		std::cout << *i <<" ";
	std::cout <<"\n";*/
    return (jacobindx);
}

int PmergeMeDeq::BinarySearch(int target)
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
void PmergeMeDeq::printDeq(void)
{
	/*std::cout << "Before : ";
	for (size_t i = 0; i < _size ; ++i)
		std::cout<< _input[i]<<" ";
	std::cout<<"\n";	*/
	/*std::deque<int> :: iterator it;
	std::cout<< "After : ";
	for (it=_MainChain.begin(); it != _MainChain.end(); ++it)
	std::cout << *it <<" ";*/
	std::cout <<"\n";
	std::cout << "Time to process a range of ";
	std::cout << _size << " elements with std::deque : " ;
	
	std::cout <<std::setprecision(8) <<_time << "ms" << std::endl;
	
}