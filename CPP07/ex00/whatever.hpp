/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:19:46 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/06 11:50:13 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
	#define WHATEVER_H

#include<iostream>

template<typename T>
const T& max(T const &a, T const &b)
{
	if(a > b)
		return(a);
	else
		return(b);
}
template<typename T>
const T& min (T const &a, T const &b)
{
	if(a < b)
		return(a);
	else
		return(b);
}
template<typename S>
void swap(S &a, S &b)
{
	 S temp;
	 temp = a;
	 a = b;
	 b = temp;
}
#endif
