/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:15:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/20 15:28:09 by erico-ke         ###   ########.fr       */
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

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return _ideas[index];
	return "";
}

void	Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}