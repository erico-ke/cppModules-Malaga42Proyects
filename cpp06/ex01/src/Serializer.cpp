/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:00:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/08 11:00:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Serializer default constructor called" << RESET);
}

Serializer::Serializer(const Serializer &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Serializer copy constructor called" << RESET);
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Serializer copy assignment operator called" << RESET);
	(void)other;
	return (*this);
}

Serializer::~Serializer(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "Serializer destructor called" << RESET);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}