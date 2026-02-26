/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:23:31 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 18:52:10 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << CONSTRUCTOR_COLOR << "Default Ice constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Ice copy constructor called" << RESET << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Ice copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice(void)
{
	std::cout << DESTRUCTOR_COLOR << "Ice destructor called" << RESET << std::endl;
}

AMateria	*Ice::clone() const
{
	AMateria	*newIce = new Ice(*this);
	return newIce;
}

void	Ice::use(ICharacter &target)
{
	std::cout << USE_COLOR << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}