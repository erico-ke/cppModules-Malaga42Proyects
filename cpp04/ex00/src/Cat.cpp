/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:03:54 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/19 17:04:54 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << CONSTRUCTOR_COLOR << "Default Cat constructor called" << RESET << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Cat copy constructor called" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Cat copy assigment constructor called" << RESET << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << DESTRUCTOR_COLOR << "Cat constructor called" << RESET << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << SOUND_COLOR << "Meow!!" << RESET << std::endl;
}
