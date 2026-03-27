/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:48:15 by erico-ke          #+#    #+#             */
/*   Updated: 2026/03/27 12:50:39 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureucrat.hpp"

Bureucrat::Bureucrat(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Default Bureucrat constructor called" << RESET);
}

Bureucrat::Bureucrat(const Bureucrat &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Bureucrat copy constructor called" << RESET);
	*this = other;
}

Bureucrat &Bureucrat::operator=(const Bureucrat &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Bureucrat copy assignment operator called" << RESET);
	if (this != &other)
	{
		
	}
	return *this;
}

Bureucrat::~Bureucrat(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "Bureucrat destructor called" << RESET);
}
