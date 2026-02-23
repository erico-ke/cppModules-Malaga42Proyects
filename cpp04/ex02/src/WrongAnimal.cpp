/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:12:42 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/20 15:13:24 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << CONSTRUCTOR_COLOR << "Default WrongAnimal constructor called" << RESET << std::endl;
	_type = "Untype";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << CONSTRUCTOR_COLOR << "WrongAnimal copy constructor called" << RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << CONSTRUCTOR_COLOR << "WrongAnimal copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << DESTRUCTOR_COLOR << "WrongAnimal destructor called" << RESET << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << SOUND_COLOR << "*Wrongs Animal absolute silence*" << RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return _type;
}
