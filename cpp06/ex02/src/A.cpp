/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:00:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/08 11:00:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"

A::A(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "A default constructor called" << RESET);
}

A::A(const A &other): Base(other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "A copy constructor called" << RESET);
}

A &A::operator=(const A &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "A copy assignment operator called" << RESET);
	if (this != &other)
		Base::operator=(other);
	return (*this);
}

A::~A(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "A destructor called" << RESET);
}