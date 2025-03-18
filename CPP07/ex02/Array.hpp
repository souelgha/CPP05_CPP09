/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:02:38 by sonouelg          #+#    #+#             */
/*   Updated: 2024/11/06 14:07:01 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include<exception>
#include<cstdlib>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

template <typename T>
class Array
{
	private :
		T *rawArray;
		unsigned int _size;
	public:
		Array(): rawArray(NULL), _size(0){}
		~Array();
		Array(unsigned int const n);
		Array(const Array & copy);
		Array& operator=(const Array & copy);		
		T & operator[](unsigned int position);
		const T & operator[](unsigned int position) const;
		unsigned int size() const;	
};

/********************* implementations  **********************/
template<typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	this->rawArray= new T[n];
	for (unsigned int i = 0; i < n ; ++i)
		this->rawArray[i] = T();
	
}
template<typename T>
Array<T>::~Array()
{
	delete[] rawArray;
}
template<typename T>
Array<T>::Array(const Array& copy): _size(copy._size)
{
	this->rawArray= new T[_size];
	for(unsigned int i = 0; i <_size; i++)
		this->rawArray[i] = copy.rawArray[i];
}
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy)
{
	if(this != &copy)
	{
		delete [] this->rawArray;
		this->_size = copy._size;
		this->rawArray= new T[this->_size];
		for(unsigned int i = 0; i <this->_size; i++)
			this->rawArray[i] = copy.rawArray[i];
	}	
	return(*this);
}
template<typename T>
unsigned int Array<T>::size() const
{
	return(_size);
}
template<typename T>
T & Array<T>::operator[](unsigned int position)
{
	if(position >= this->_size )
		throw std::out_of_range("array index out of range");
	else
		return(this->rawArray[position]);
}
template<typename T>
const T& Array<T>::operator[](unsigned int position) const
{
	if(position >= this->_size )
		throw std::out_of_range("array index out of range");
	else
		return(this->rawArray[position]);
}
template<typename T>
std::ostream& operator<<(std::ostream &os, const Array<T> &tab)
{
	
	os << "tab[" << tab.size()<<"]=["  ;
	for(unsigned int i = 0; i < tab.size(); i++)
	{
		os<< tab[i];
		if(i < tab.size() - 1)
			os <<", ";
	}
	os<<"]";
	return(os);
}