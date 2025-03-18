/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:52:09 by sonia             #+#    #+#             */
/*   Updated: 2024/11/13 13:42:45 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void test01()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);	
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "------------------------------" << std::endl;
    MutantStack<int> s(mstack);
    MutantStack<int>::iterator it1;
    for (it1 = s.begin(); it1 != s.end(); ++it1)
    {
        std::cout << *it1 << std::endl;
    }
}
void test02()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);	
	mstack.push_back(0);
	
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "------------------------------" << std::endl;
	 for (it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
	
}
int main()
{
	std::cout<< "/******** test01 : stack *********/"<< std::endl;
	test01();
	std::cout<< "/******** test02 : list *********/"<< std::endl;
	test02();
	return 0;
}