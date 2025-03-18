/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:02:19 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/13 11:01:29 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(int size): N(size)
{
	tab.reserve(N);
}
Span::~Span(){}
Span::Span(const Span& copy): N(copy.N), tab(copy.tab){}
Span& Span::operator=(const Span& copy)
{
	if(this != &copy)
	{
		this->N=copy.N;
		this->tab= copy.tab;
	}
	return(*this);
}
void Span::addNumber(int num)
{
	if((tab.size()) >= N)
		throw std::out_of_range("vector is full. no more space");
	tab.push_back(num);
}
const char* Span::lesThanTwoException::what() const throw() 
{
    return "Not enough number. need at least 2";
}
int Span::shortestSpan()
{
	if(tab.size() < 2 || tab.empty())
		throw Span::lesThanTwoException();
	int num = abs(tab[0] - tab[1]);
	for (size_t i = 0; i < tab.size() -1; ++i)
	{
		for(size_t j = i + 1 ; j < tab.size(); ++j)
		{
			if(abs(tab[i] -  tab[j] ) < num)
				num = abs(tab[i] -  tab[j] );			
		}
	}
	return(num);
}
int Span::longestSpan()
{
	if(tab.size() < 2 || tab.empty())
		throw Span::lesThanTwoException();
	int num = abs(tab[0] - tab[1]);
	for (size_t i = 0; i < tab.size() - 1; ++i)
	{
		for(size_t j = i + 1 ; j < tab.size() ; ++j)
		{
			if(abs(tab[i] -  tab[j] ) > num)
				num = abs(tab[i] -  tab[j]);	
		}
	}
	return(num);
}
//range version
void Span::RangeIt(std::vector<int>::iterator start, std::vector<int>::iterator end) 
{
    if (tab.size() + std::distance(start, end) > this->N) 
        throw std::out_of_range("too big range");
    tab.insert(tab.end(), start, end);
}

void Span::display() const
{
	for(std::vector<int>::const_iterator it = tab.begin(); it != tab.end() ; it++)
		std::cout<< *it << std::endl;
	std::cout<< "size: "<< tab.size() << std::endl;
}