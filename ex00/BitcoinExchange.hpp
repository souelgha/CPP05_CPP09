/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:57:45 by sonia             #+#    #+#             */
/*   Updated: 2024/11/15 16:27:33 by sonia            ###   ########.fr       */
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
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange & operator=(const BitcoinExchange &other);

		void parsExchange();
		void parsInput(const std::string argv1);
		float compareDate(const std::string &dateinput);
		bool checkDate(std::string &date);		
};

bool checkValue(float value);