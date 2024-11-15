/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:58:04 by sonia             #+#    #+#             */
/*   Updated: 2024/11/15 19:35:03 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include<algorithm>
#include<stack>
#include<iterator>

class RPN
{
	private:
		std::stack<int> _pile;
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN & operator=(const RPN& other);
		int multiply(const int &a, const int &b);
		int divise(const int &a, const int &b);
		int add(const int &a, const int &b);
		int soustract(const int &a, const int &b);
		void resultRPN() const;

};
