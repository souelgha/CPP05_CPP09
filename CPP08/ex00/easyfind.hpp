/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:40:57 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/13 11:53:36 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include<iostream>
#include<algorithm>
#include<exception>
#include<vector>
#include<list>
#include<iterator>

template<typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if(it== container.end())
		throw std::range_error ("No value find !");
	return(it);	
}
