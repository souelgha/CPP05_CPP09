/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/09 16:43:33 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	this->_oddVal = -1;
	this->_timev = 0;
	this->_timeq = 0;
	this->_size = 0;
}

PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}
PmergeMe & PmergeMe::operator=(const PmergeMe &other)
{
	if(this!= &other)
		*this=other;
	return(*this);
}
void PmergeMe::ft_stoi_V( int argc, char **data)
{
	for (int i = 1; i < argc ; ++i)
	{
		std::istringstream ss(data[i]);
		int value;
		ss >> value;
		_inputv.push_back(value);
	}
	_size = _inputv.size();
}

void PmergeMe::sort_numbers_V( int argc, char **data)
{	
	std::clock_t startTime = std::clock();
	ft_stoi_V(argc, data);
	
	if(_inputv.size() %2 != 0)
	{
		_oddVal = _inputv.back();
		_inputv.pop_back();
	}

	_pairesv = CreatepairesV(_inputv);
	std::vector<int> jacobindxs = CalculJacobindxV(_inputv.size());
	if(_pairesv.size() == 0)
	{
		_MainChainv.push_back(_oddVal);
		_timev = 1000.0 * (std::clock() - startTime) / (double) CLOCKS_PER_SEC;
		printV();
		return;
	}

	sort_pairs_V(_pairesv);

	_MainChainv.push_back(_pairesv[0].first);
	_MainChainv.push_back(_pairesv[0].second);
	for (size_t i = 1; i <_pairesv.size() ; ++i)
		_MainChainv.push_back(_pairesv[i].second);

	for (size_t i = 0; i < jacobindxs.size(); i++)
    {
        if (size_t(jacobindxs[i] - 1) >= _pairesv.size())
            continue;
        int index = BinarySearchV(_pairesv[jacobindxs[i] - 1].second);
		std::vector<int>::iterator search= _MainChainv.begin() + index;
		std::vector<int>::iterator pos = std::upper_bound(_MainChainv.begin(),search, _pairesv[jacobindxs[i] - 1].first );
        _MainChainv.insert(pos, _pairesv[jacobindxs[i] - 1].first);	
    }
	if(_oddVal != -1)
	{
		std::vector<int>::iterator pos = std::upper_bound(_MainChainv.begin(),_MainChainv.end(), _oddVal);
        _MainChainv.insert(pos, _oddVal);
	}
	_timev = 1000.0 * (std::clock() - startTime) / (double) CLOCKS_PER_SEC;

}
std::vector<std::pair<int, int> > PmergeMe::CreatepairesV(std::vector<int> &input)
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
void PmergeMe::sort_pairs_V(std::vector<std::pair<int, int> >  &pairs) 
{
    if (pairs.size() <= 1)
        return; 
	
    // divise le vector de paires en 2 moities
    size_t middle = pairs.size() / 2;
    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + middle);	
  	std::vector<std::pair<int, int> > right(pairs.begin() + middle, pairs.end());
	
	/* visualisation des paires creees */
	// for (size_t i=0; i < pairs.size(); i++)
	// 	std::cout << "("<< pairs[i].first<< "," << pairs[i].second << ") ; ";
	// std::cout << "\n";
   
    sort_pairs_V(left);
    sort_pairs_V(right);

    MergeSortedV(left, right, pairs);
}

void PmergeMe::MergeSortedV( std::vector<std::pair<int, int> >  &leftH, std::vector<std::pair<int, int> >  &rightH, std::vector<std::pair<int, int> > &pairs)
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
	
	/* affichage des MergeSort */
	// std::cout<< "MG: ";
	// for (size_t i=0; i < pairs.size(); i++)
	// 	std::cout << "("<< pairs[i].first<< "," << pairs[i].second << ") ; ";
	// std::cout << "\n";
}

std::vector<int> PmergeMe::CalculJacobindxV(size_t lenght) 
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
	/* affichage de la suite de jacobsthal */
	// std::vector<int> :: iterator i;
	// std::cout<< "Jacobsthal : ";
	// for (i=jacobindx.begin(); i != jacobindx.end(); ++i)
	// 	std::cout << *i <<" ";
	// std::cout <<"\n";
    return (jacobindx);
}

int PmergeMe::BinarySearchV(int target)
{
	int low = 0;
	int high = _MainChainv.size() - 1;
	
	while(low <= high)
	{
		int middle = low + (high - low)/2;
		if(target == _MainChainv[middle])
			return(middle);
		if(target < _MainChainv[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}
	return(-1);	
}
void PmergeMe::printV(void)
{
	std::vector<int> :: iterator it;
	std::cout<< MAGENTA << "After : ";
	for (it=_MainChainv.begin(); it != _MainChainv.end(); ++it)
		std::cout << *it <<" ";
	std::cout << WHITE <<"\n";
}
void PmergeMe::printVTime(void)
{
	std::cout << CYAN << "Time to process a range of ";
	std::cout << _size << " elements with <std::vector> : " ;	
	std::cout <<std::setprecision(8) <<_timev << "ms" << WHITE<< std::endl;

}

void PmergeMe::ft_stoi_Q( int argc, char **data)
{
	for (int i = 1; i < argc ; ++i)
	{
		std::istringstream ss(data[i]);
		int value;
		ss >> value;
		_inputq.push_back(value);
	}
	_size = _inputq.size();
}

void PmergeMe::sort_numbers_Q( int argc, char **data)
{
	std::clock_t startTime = std::clock();
	ft_stoi_Q(argc, data);
	if(_inputq.size() %2 != 0)
	{
		_oddVal = _inputq.back();
		_inputq.pop_back();
	}

	_pairesq = CreatepairesQ(_inputq);
	std::deque<int> jacobindxs = CalculJacobindxQ(_inputq.size());
	if(_pairesq.size() == 0)
	{
		_MainChainq.push_back(_oddVal);
		_timeq = 1000.0 * (std::clock() - startTime) / (double) CLOCKS_PER_SEC;
		printQ();
		return;
	}

	sort_pairs_Q(_pairesq);

	_MainChainq.push_back(_pairesq[0].first);
	_MainChainq.push_back(_pairesq[0].second);
	for (size_t i = 1; i <_pairesq.size() ; ++i)
		_MainChainq.push_back(_pairesq[i].second);

	for (size_t i = 0; i < jacobindxs.size(); i++)
    {
        if (size_t(jacobindxs[i] - 1) >= _pairesq.size())
            continue;
        int index = BinarySearchQ(_pairesq[jacobindxs[i] - 1].second);
		std::deque<int>::iterator search= _MainChainq.begin() + index;
		std::deque<int>::iterator pos = std::upper_bound(_MainChainq.begin(),search, _pairesq[jacobindxs[i] - 1].first );
        _MainChainq.insert(pos, _pairesq[jacobindxs[i] - 1].first);	
    }
	if(_oddVal != -1)
	{
		std::deque<int>::iterator pos = std::upper_bound(_MainChainq.begin(),_MainChainq.end(), _oddVal);
        _MainChainq.insert(pos, _oddVal);
	}
	_timeq = 1000.0 * (std::clock() - startTime) / (double) CLOCKS_PER_SEC;

}
std::deque<std::pair<int, int> > PmergeMe::CreatepairesQ(std::deque<int> &input)
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
void PmergeMe::sort_pairs_Q(std::deque<std::pair<int, int> >  &pairs) 
{
    if (pairs.size() <= 1)
        return; 
	
    size_t middle = pairs.size() / 2;
    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + middle);	
  	std::deque<std::pair<int, int> > right(pairs.begin() + middle, pairs.end());
	
    sort_pairs_Q(left);
    sort_pairs_Q(right);

    MergeSortedQ(left, right, pairs);
}

void PmergeMe::MergeSortedQ( std::deque<std::pair<int, int> >  &leftH, std::deque<std::pair<int, int> >  &rightH, std::deque<std::pair<int, int> > &pairs)
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

std::deque<int> PmergeMe::CalculJacobindxQ(size_t lenght) 
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

        for (int j = jacobsthalArray[i] - 1; j > lastJNum; j--)
            jacobindx.push_back(j);
        lastJNum = jacobsthalArray[i];
    }
    return (jacobindx);
}

int PmergeMe::BinarySearchQ(int target)
{
	int low = 0;
	int high = _MainChainq.size() - 1;
	
	while(low <= high)
	{
		int middle = low + (high - low)/2;
		if(target == _MainChainq[middle])
			return(middle);
		if(target < _MainChainq[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}
	return(-1);	
}
void PmergeMe::printQ(void)
{
	std::deque<int> :: iterator it;
	std::cout<< GREEN << "After : ";
	for (it=_MainChainq.begin(); it != _MainChainq.end(); ++it)
		std::cout << *it <<" ";
	std::cout << WHITE <<"\n";
}
void PmergeMe::printQTime(void)
{
	std::cout << GREEN << "Time to process a range of ";
	std::cout << _size << " elements with <std::deque >: " ;
	
	std::cout <<std::setprecision(8) <<_timeq << "ms" << WHITE << std::endl;
	
}
