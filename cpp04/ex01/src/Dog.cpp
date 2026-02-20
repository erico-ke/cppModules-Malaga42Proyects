/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:56:53 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/20 15:13:24 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << CONSTRUCTOR_COLOR << "Default Dog constructor called" << RESET << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << CONSTRUCTOR_COLOR << "Dog copy constructor called" << RESET << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << DESTRUCTOR_COLOR << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << SOUND_COLOR << "Bark Bark" << RESET << std::endl;
}
