/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:48:15 by erico-ke          #+#    #+#             */
/*   Updated: 2026/03/27 13:23:49 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureucrat.hpp"

Bureucrat::Bureucrat(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Default Bureucrat constructor called" << RESET);
}

Bureucrat::Bureucrat(std::string name, int grade)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Bureucrat constructor called" << RESET);
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
		_grade = other._grade;
	}
	return *this;
}

Bureucrat::~Bureucrat(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "Bureucrat destructor called" << RESET);
}
