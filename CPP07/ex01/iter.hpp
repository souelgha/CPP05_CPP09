/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:47:45 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/06 12:05:04 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>

template<typename I>
void addtwo(I &i)
{
	i+=2;
}
template<typename I>
void printTab(I const &i) 
{
	std::cout << i << std::endl;
}

template<typename A , typename F>
void iter(A* array, const size_t b, F func)
{
	for (size_t i = 0; i < b; i++)
		func(array[i]);
}

