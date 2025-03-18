/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:53:30 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/31 11:13:51 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::~Serializer(){}
Serializer::Serializer(const Serializer& copy)
{
	*this=copy;
}
Serializer& Serializer::operator=(const Serializer& copy)
{
	(void)copy;
	return(*this);
}
uintptr_t Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}
		