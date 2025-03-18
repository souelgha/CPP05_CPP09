/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:15:06 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/15 17:17:42 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	BitcoinExchange::initMap();
}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_exchange=other._exchange;
}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if(this != &other)
		this->_exchange = other._exchange;
	return(*this);
}

 void BitcoinExchange::initMap()
{
	std::ifstream vfile("data.csv");
	std::string line;

	if(!vfile)
		std::cout<< "erreur de lecture du fichier"<< std::endl;
	std::getline(vfile, line);
	while(std::getline(vfile, line))
	{
		std::istringstream lstream(line);
		std::string date;
		float value;

		if(std::getline(lstream, date, ','))
		{
			lstream >> value;
			_exchange[date] = value;
		}		
	}
	vfile.close();
}
float BitcoinExchange::compareDate(const std::string &dateInput)
{
	std::map<std::string, float>::iterator it;
	it= _exchange.begin();
	while(dateInput > it->first)
		it++;
	if(dateInput == it->first)
		return(it->second);
	else if(dateInput < it->first)
	{
		--it;
		return(it->second);
	}		
	std::cerr << "no matching found"<< std::endl;
	return(0);
}
void BitcoinExchange::parsInput(const std::string argv1)
{
	std::ifstream vfile(argv1.c_str());
	std::string line;

	if(!vfile)
	{
		std::cout<< "erreur de lecture du fichier"<< std::endl;
		return;
	}
	std::getline(vfile, line);
	if (line != "date | value")
	{
		std::cout << "fichier invalide "<< std::endl;
		vfile.close();
		return;
	}
	while(std::getline(vfile, line))
	{
		std::istringstream lstream(line);
		std::string date;
		float value;

		if(std::getline(lstream, date, '|') &&(BitcoinExchange::checkDate(date)))
		{
			if (!(lstream >> value) )
				std::cerr << "Error: no value " << std::endl;			
			else if(checkValue(value))
			{
				std::string date1= date.substr(0, 10);
				std::cout<< date1 << " => "<< value << " = " ;
				float f = BitcoinExchange::compareDate(date1);
				std::cout << f * value << std::endl;
			}				
		}
	}
	vfile.close();
}

bool BitcoinExchange::checkDate(std::string &date)
{
	int year, month, day;
	char delim1, delim2;

	std::istringstream dateStream(date);
	if(!(dateStream >> year >> delim1 >> month >> delim2 >> day) 
		|| delim1 != '-' || delim2 != '-')
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return(false);
	}
	else if(year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return(false);
	}
	int MonthTable[]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if(day > MonthTable[month - 1])
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return(false);
	}
	std::map<std::string, float>::iterator it= _exchange.begin();
	std::map<std::string, float>::iterator ite= _exchange.end();
	std::string date1= date.substr(0, 10);
	ite--;
	if(date1 < it->first || date1 > ite->first)
	{
		std::cerr << "Error: date out of range => " << date1 << std::endl;
		return(false);
	}
	return true;
}

bool checkValue(float value)
{
	if(value < 0)
	{
		std::cerr << "Error: not positive value " << std::endl;
		return(false);
	}
	else if(value > 1000)
	{
		std::cerr << "Error: too large number " << std::endl;
		return(false);
	}
	return true;
}
