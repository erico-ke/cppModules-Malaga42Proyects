/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:56:53 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/19 17:02:14 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << CONSTRUCTOR_COLOR << "Default Dog constructor called" << RESET << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Dog copy constructor called" << RESET << std::endl;
	if (this != &other)
		*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Dog copy assigment constructor called" << RESET << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << DESTRUCTOR_COLOR << "Dog constructor called" << RESET << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << SOUND_COLOR << "Bark Bark" << RESET << std::endl;
}
