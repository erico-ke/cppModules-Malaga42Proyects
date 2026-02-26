/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:47:42 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 17:11:27 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void) : _name("Default")
{
	std::cout << CONSTRUCTOR_COLOR << "Default Character constructor called" << RESET << std::endl;
	this->_name = "Default";
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
	for (int i = 0; i < 500; i++)
		this->_rest[i] = NULL;
}

Character::Character(std::string name)
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
	for (int i = 0; i < 500; i++)
		this->_rest[i] = NULL;
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
		this->_name = getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->_slot[i] != NULL)
				delete this->_slot[i];
			if (other._slot[i] != NULL)
				this->_slot[i] = other._slot[i]->clone();
			else
				this->_slot[i] = NULL;
		}
		for (int i = 0; i < 500; i++)
		{
			if (this->_rest[i] != NULL)
				delete this->_rest[i];
			if (other._rest[i] != NULL)
				this->_rest[i] = other._rest[i]->clone();
			else
				this->_rest[i] = NULL;	
		}
	}
	return *this;
}

Character::~Character(void)
{
	std::cout << DESTRUCTOR_COLOR << "Character destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_slot[i] != NULL)
			delete this->_slot[i];
	for (int i = 0; i < 500; i++)
		if (this->_rest[i] != NULL)
			delete this->_rest[i];
}

std::string const&	Character::getName() const
{
	return (this->_name);
}

