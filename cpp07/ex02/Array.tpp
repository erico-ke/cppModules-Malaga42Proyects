/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:22:57 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/09 13:33:33 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Array.hpp"

template<typename T>
Array<T>::Array(void) : _data(NULL), _size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (_size > 0)
		_data = new T[_size]();
}

template<typename T>
Array<T>::Array(const Array<T> &other) : _data(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		T *newData = NULL;

		if (other._size > 0)
		{
			newData = new T[other._size];
			for (unsigned int i = 0; i < other._size; ++i)
				newData[i] = other._data[i];
		}
		delete[] _data;
		_data = newData;
		_size = other._size;
	}
	return *this;
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] _data;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Array index out of bounds");
	return _data[index];
}

template<typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Array index out of bounds");
	return _data[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
