/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:15:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/20 15:13:24 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(void)
{
	std::cout << CONSTRUCTOR_COLOR << "Default Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Brain copy constructor called" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Brain copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		int i = -1;
		while (++i <= 99)
		{
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << DESTRUCTOR_COLOR << "Brain destructor called" << RESET << std::endl;
}