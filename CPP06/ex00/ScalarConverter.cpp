/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:19:56 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/29 16:32:25 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter(){}

bool ExcepType(std::string type)
{
	std::string exceptype[7]={ "-inf", "+inf", "nan", "inf", "-inff", "+inff", "nanf"};
	for(int i = 0; i< 7; ++i)
	{
		if(type.compare(exceptype[i])== 0)
		{
			std::cout<< "char: impossible" << std::endl;
			std::cout<< "int: impossible" << std::endl;
			if (i < 4)
			{	std::cout<< "float: "  << exceptype[i] << "f"<< std::endl;
				std::cout<< "double: " << exceptype[i] << std::endl;
			}
			else
			{
				std::cout<< "float: "  << exceptype[i] << std::endl;
				std::size_t pos = exceptype[i].find_last_of("f");
				std::string str= exceptype[i].substr(0, pos);
				std::cout<< "double: " << str << std::endl;
			}
			return(true);
		}				
	}
	return(false);
}
std::string IsChar(std::string type)
{
	std::string ToChar="";

	float Tof= std::atof(type.c_str());
	char c= static_cast<char>(Tof);

	if(!std::isdigit(type[0]) &&(type.length() == 1))
		ToChar = static_cast<char>(type[0]);
	else if ((!std::isdigit(type[0]) &&(type.length() > 1)))
		return("impossible");
	else if(!std::isprint(c))
		return("Non displayable");
	else
		ToChar = static_cast<char>(Tof);
	return ToChar;
}

void ScalarConverter::Convert(const std::string &type)
{
	if(ExcepType(type))
		return;	
	if(type.length() > 1)
	{
		if(std::isalpha(type[0]) && (std::isalnum(type[1]) || type[1]=='.'))
		{
			std::cout<< "invalid arguments!" << std::endl;
			return;
		}
		for (size_t i = 1; i < type.length() -1; i++)
		{
			if(std::isalpha(type[i]))
			{
				std::cout<< "invalid arguments!" << std::endl;
				return;
			}
		}
		if(std::isalpha(type[type.length()-1]) && (type[type.length()-1] != 'f') && (type[type.length()-1] != 'F'))
		{
			std::cout<< "invalid arguments!"<< type[type.length()-1] << std::endl;
			return;
		}		
	}
	float convToFloat = 0;
	double convToDble=  0;
	int convToInt = 0;

	if((IsChar(type).compare("impossible") != 0) && (IsChar(type).compare("Non displayable") != 0) && type.length() == 1)
	{
		std::cout<< "char: '" << IsChar(type)<< "'" << std::endl;
		convToInt= static_cast<int>(type[0]);
		convToDble= static_cast<double>(type[0]);
		convToFloat = static_cast<float>(type[0]);

	}
	else 
	{
		if((IsChar(type).compare("impossible") != 0) && (IsChar(type).compare("Non displayable") != 0))
			std::cout<< "char: '" << IsChar(type)<< "'" << std::endl;
		else
			std::cout<< "char: " << IsChar(type)<<std::endl;
		convToFloat = std::atof(type.c_str());
		convToInt=  static_cast<int>(convToFloat);
		convToDble= static_cast<double>(convToFloat);
	}
	
	std::cout<< "int: " << convToInt <<std::endl;
	std::cout<< "float: " << std::fixed<< std::setprecision(1)<< convToFloat << "f"<<std::endl;
	std::cout<< "double: " << std::fixed << std::setprecision(1) << convToDble <<std::endl;
}
