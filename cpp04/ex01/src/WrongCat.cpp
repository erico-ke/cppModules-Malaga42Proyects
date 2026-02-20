/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:19:18 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/20 15:13:24 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << CONSTRUCTOR_COLOR << "Default WrongCat constructor called" << RESET << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << CONSTRUCTOR_COLOR << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << CONSTRUCTOR_COLOR << "WrongCat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << DESTRUCTOR_COLOR << "WrongCat destructor called" << RESET << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << SOUND_COLOR << "Meow!!" << RESET << std::endl;
}
