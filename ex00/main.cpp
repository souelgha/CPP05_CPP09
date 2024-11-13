/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:58:43 by sonia             #+#    #+#             */
/*   Updated: 2024/11/13 19:22:13 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main()
{
	std::ifstream vfile("input.txt");
	std::string line;

	if(!vfile)
		std::cout<< "erreur de lecture du fichier"<< std::endl;
	std::getline(vfile, line);
	std::istringstream lstream(line);
	std::cout<< line << std::endl;
	while(std::getline(vfile, line))
	{
		std::istringstream lstream(line);
		std::string date;
		float value;

		if(std::getline(lstream, date, '|'))
		{
			lstream >> value;
			std::cout<< date << " | "<< value << std::endl;
		}
	}
	vfile.close();
	return(0);
}