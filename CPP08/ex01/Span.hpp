/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:12:23 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/12 11:59:55 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include<algorithm>
#include<exception>
#include<vector>
#include<list>
#include<iterator>
#include<stdlib.h>

class Span
{
	private:
		unsigned int N;
		std::vector<int> tab;
	public:
		Span(int size);
		~Span();
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		void addNumber(int num);
		void RangeIt(std::vector<int>::iterator start, std::vector<int>::iterator end);
		void display() const;

		int shortestSpan();
		int longestSpan();
	
		class lesThanTwoException : public std::exception 
		{
            public:
               const char *what() const throw();
		};

};
