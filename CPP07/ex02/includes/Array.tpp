/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:50:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/01 19:06:30 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : n(0)
{
	this->array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : n(n)
{
	this->array = new T[this->n];
	for (unsigned int i = 0; i < this->n; i++)
		this->array[i] = T();
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	this->array = NULL;
	*this = copy;	
}

template <typename T>
Array<T>::~Array()
{
	delete [] array;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->n);
}

template <typename T>
Array<T>& Array<T>::operator =(const Array<T>& right)
{
	if (this == &right)
		return (*this);
	
	delete [] this->array;
	this->n = right.n;
	this->array = new T[this->n];
	for (unsigned int i = 0; i < this->n; i++)
		this->array[i] = right.array[i];
	
	return (*this);
}

template <typename T>
T& Array<T>::operator [](unsigned int index)
{
	if (index < 0 || index >= this->n)
		throw Array<T>::IndexOutOfBoundsException();
	return (this->array[index]);
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Array: index out of bounds");
}

