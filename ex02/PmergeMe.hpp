/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:27:30 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/09 16:20:35 by sonia            ###   ########.fr       */
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
#include<iomanip>
#include<climits>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"


class PmergeMe
{
		private :
			int 	_oddVal;
			double _timev;
			double _timeq;
			size_t _size;
			std::vector<int> _inputv;
			std::vector<int> _MainChainv;
			std::vector<std::pair<int, int > > _pairesv;
			std::deque<int> _inputq;
			std::deque<int> _MainChainq;
			std::deque<std::pair<int, int > > _pairesq;
			PmergeMe(const PmergeMe &other);
			PmergeMe & operator=(const PmergeMe &other);

	public:
		PmergeMe();
		~PmergeMe();
		void ft_stoi_V(int argc, char **data);
		void sort_numbers_V( int argc, char **data);
		std::vector<std::pair<int, int> > CreatepairesV(std::vector<int> &input);
		void sort_pairs_V(std::vector<std::pair<int, int> >  &pairs);
		void MergeSortedV(std::vector<std::pair<int, int> >  &leftH, 
						std::vector<std::pair<int, int> >  &rightH, 
						std::vector<std::pair<int, int> > &pairs);
		std::vector<int> CalculJacobindxV(size_t lenght);
		int BinarySearchV(int target);
		void printV(void);
		void printVTime(void);

	public:
		void ft_stoi_Q(int argc, char **data);
		void sort_numbers_Q( int argc, char **data);
		std::deque<std::pair<int, int> > CreatepairesQ(std::deque<int> &input);
		void sort_pairs_Q(std::deque<std::pair<int, int> >  &pairs);
		void MergeSortedQ(std::deque<std::pair<int, int> >  &leftH, 
						std::deque<std::pair<int, int> >  &rightH, 
						std::deque<std::pair<int, int> > &pairs);
		std::deque<int> CalculJacobindxQ(size_t lenght);
		int BinarySearchQ(int target);
		void printQ(void);
		void printQTime(void);	

};
