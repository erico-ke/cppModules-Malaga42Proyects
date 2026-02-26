/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:25:11 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 18:50:31 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

AMateria::AMateria(void)
{
	std::cout << CONSTRUCTOR_COLOR << "Default AMateria constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << CONSTRUCTOR_COLOR << "AMateria copy constructor called" << RESET << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << CONSTRUCTOR_COLOR << "AMateria copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria(void)
{
	std::cout << DESTRUCTOR_COLOR << "AMateria destructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << CONSTRUCTOR_COLOR << "Materia constructor called, type setted to : " << type << RESET << std::endl; 
}

std::string const	&AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << ERROR_COLOR << "Default materia can't interact with " << target.getName() << RESET << std::endl;
}