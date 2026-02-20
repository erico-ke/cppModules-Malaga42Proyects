/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:03:54 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/20 15:13:24 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << CONSTRUCTOR_COLOR << "Default Cat constructor called" << RESET << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << CONSTRUCTOR_COLOR << "Cat copy constructor called" << RESET << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << DESTRUCTOR_COLOR << "Cat destructor called" << RESET << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << SOUND_COLOR << "Meow!!" << RESET << std::endl;
}
