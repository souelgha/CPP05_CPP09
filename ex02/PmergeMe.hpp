/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:27:30 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/04 14:44:36 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<iterator>
#include<utility>

std::vector<std::pair<int, int> > Createpaires(std::vector<int> &input);
void sort_pairs(std::vector<std::pair<int, int> >  &pairs);
void MergeSorted( std::vector<std::pair<int, int> >  &leftH, std::vector<std::pair<int, int> >  &rightH, 
				std::vector<std::pair<int, int> > &pairs);
void sort_numbers( std::vector<int> &input);
std::vector<int> CalculJacobindx(size_t lenght);
int BinarySearch(int target, std::vector<int> &MainChain);


class PmergeMe
{
	private :
		int _oddVal;
		std::vector<int> _input;
		std::vector<std::pair<int, int > > _paires;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe & operator=(const PmergeMe &other);


};