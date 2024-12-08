/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:27:30 by sonouelg          #+#    #+#             */
/*   Updated: 2024/12/08 19:42:22 by sonia            ###   ########.fr       */
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
		double _time;
		size_t    _size;
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
		void printVect(void);


};
class PmergeMeDeq :public PmergeMe
{
	private :
		int _oddVal;
		double _time;
		size_t    _size;
		std::deque<int> _input;
		std::deque<int> _MainChain;
		std::deque<std::pair<int, int > > _paires;
		
	public:
		PmergeMeDeq();
		~PmergeMeDeq();
		PmergeMeDeq(const PmergeMeDeq &other);
		PmergeMeDeq & operator=(const PmergeMeDeq &other);
		void ft_stoi(int argc, char **data);
		void sort_numbers( int argc, char **data);
		std::deque<std::pair<int, int> > Createpaires(std::deque<int> &input);
		void sort_pairs(std::deque<std::pair<int, int> >  &pairs);
		void MergeSorted(std::deque<std::pair<int, int> >  &leftH, 
						std::deque<std::pair<int, int> >  &rightH, 
						std::deque<std::pair<int, int> > &pairs);
		
		std::deque<int> CalculJacobindx(size_t lenght);
		int BinarySearch(int target);
		void printDeq(void);


};