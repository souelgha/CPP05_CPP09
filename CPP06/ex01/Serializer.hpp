/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:53:21 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/31 11:13:42 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
	#define SERIALIZER_H

#include<iostream>
#include<stdint.h>

typedef struct Data
{
	int data1;
	int data2;
}Data;

class Serializer
{
	private :
	Serializer();
	~Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& copy);
		
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);


};



#endif