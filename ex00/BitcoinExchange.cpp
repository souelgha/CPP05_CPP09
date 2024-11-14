/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:15:06 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/14 18:23:45 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::parsExchange()
{
	std::ifstream vfile("data1.csv");
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
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	for (std::map<std::string, float>::iterator it = _exchange.begin(); it != _exchange.end();++it )
		std::cout << it->first << " : " << it->second << std::endl;
}
void parsInput(std::string argv1)
{
	std::ifstream vfile(argv1.c_str());
	std::string line;

	if(!vfile)
		std::cout<< "erreur de lecture du fichier"<< std::endl;
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

		if(std::getline(lstream, date, '|') &&(checkDate(date)))
		{
			if (!(lstream >> value) )
				std::cerr << "Error: no value " << std::endl;			
			else if(checkValue(value))
				std::cout<< date << " => "<< value << " = val x exrate"<< std::endl;
		}
		
	}
	vfile.close();
}

bool checkDate(std::string &date)
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
	if(year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
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
	return true;
}

bool checkValue(float value)
{
	if(!value)
	{
		std::cerr << "Error: no value " << std::endl;
		return(false);
	}
	else if(value < 0)
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
