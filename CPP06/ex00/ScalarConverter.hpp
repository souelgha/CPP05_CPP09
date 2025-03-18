/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:57:32 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/29 11:44:40 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
	#define SCALARCONVERTER_H

#include<iostream>
#include<cctype>
#include<sstream>
#include<cstdlib>
#include<string> 
#include<iomanip>


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);

	public:
	
		~ScalarConverter();
		void static Convert(const std::string &str);

};
#endif