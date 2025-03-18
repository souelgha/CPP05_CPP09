/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:08:51 by sonia             #+#    #+#             */
/*   Updated: 2024/11/13 13:32:08 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include<algorithm>
#include<exception>
#include<vector>
#include<stack>
#include<list>
#include<iterator>
#include<stdlib.h>

template<typename T, typename c = std::deque<T> > 
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
		~MutantStack()
		{
			this->c.clear();
		}
		MutantStack(const MutantStack &other): std::stack<T>(other){}
		MutantStack & operator=(const MutantStack &other)
		{
			if(this != &other)
				this->c = other.c;
			return(*this);
		}
		
		typedef typename c::iterator iterator;
		iterator begin()
		{
			return(this->c.begin());
		}
		iterator end()
		{
			return(this->c.end());
		}
};
