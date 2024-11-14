/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:57:45 by sonia             #+#    #+#             */
/*   Updated: 2024/11/14 18:26:08 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include<iterator>
#include<map>


class BitcoinExchange
{
	private:
		std::map<std::string, float> _exchange;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void parsExchange();
		
};
void parsInput(std::string argv1);
bool checkDate(std::string &date);
bool checkValue(float value);