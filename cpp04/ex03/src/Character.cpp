/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:47:42 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 15:51:13 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void) : _name("Default")
{
	std::cout << CONSTRUCTOR_COLOR << "Default Character constructor called" << RESET << std::endl;
	
}

Character::Character(const Character &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Character copy constructor called" << RESET << std::endl;
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Character copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		
	}
	return *this;
}

Character::~Character(void)
{
	std::cout << DESTRUCTOR_COLOR << "Character destructor called" << RESET << std::endl;
}
