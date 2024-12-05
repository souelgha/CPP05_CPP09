/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:27:30 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/05 17:47:41 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<ctime>
#include<iterator>
#include<utility>
#include<sstream>


class PmergeMe
{
	
	public:
		PmergeMe();
		virtual ~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe & operator=(const PmergeMe &other);

};

class PmergeMeVect :public PmergeMe
{
	private :
		int _oddVal;
		std::vector<int> _input;
		std::vector<int> _MainChain;
		std::vector<std::pair<int, int > > _paires;
		
	public:
		PmergeMeVect();
		~PmergeMeVect();
		PmergeMeVect(const PmergeMeVect &other);
		PmergeMeVect & operator=(const PmergeMeVect &other);
		void ft_stoi(int argc, char **data);
		void sort_numbers( int argc, char **data);
		std::vector<std::pair<int, int> > Createpaires(std::vector<int> &input);
		void sort_pairs(std::vector<std::pair<int, int> >  &pairs);
		void MergeSorted(std::vector<std::pair<int, int> >  &leftH, 
						std::vector<std::pair<int, int> >  &rightH, 
						std::vector<std::pair<int, int> > &pairs);
		
		std::vector<int> CalculJacobindx(size_t lenght);
		int BinarySearch(int target);


};