/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:39:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/20 15:13:24 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(void)
{
	std::cout << CONSTRUCTOR_COLOR << "Default Animal constructor called" << RESET << std::endl;
	_type = "Untype";
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << CONSTRUCTOR_COLOR << "Animal copy constructor called" << RESET << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Animal copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << DESTRUCTOR_COLOR << "Animal destructor called" << RESET << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << SOUND_COLOR << "*Absolute silence*" << RESET << std::endl;
}

std::string	Animal::getType(void) const
{
	return _type;
}
