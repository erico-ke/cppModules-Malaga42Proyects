/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:00:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/08 11:00:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/C.hpp"

C::C(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "C default constructor called" << RESET);
}

C::C(const C &other): Base(other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "C copy constructor called" << RESET);
}

C &C::operator=(const C &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "C copy assignment operator called" << RESET);
	if (this != &other)
		Base::operator=(other);
	return (*this);
}

C::~C(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "C destructor called" << RESET);
}