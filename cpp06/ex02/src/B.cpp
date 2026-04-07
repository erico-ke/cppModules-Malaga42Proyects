/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:00:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/08 11:00:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/B.hpp"

B::B(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "B default constructor called" << RESET);
}

B::B(const B &other): Base(other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "B copy constructor called" << RESET);
}

B &B::operator=(const B &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "B copy assignment operator called" << RESET);
	if (this != &other)
		Base::operator=(other);
	return (*this);
}

B::~B(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "B destructor called" << RESET);
}