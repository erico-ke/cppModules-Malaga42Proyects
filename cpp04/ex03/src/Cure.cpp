/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:59 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 18:52:10 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << CONSTRUCTOR_COLOR << "Default Cure constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Cure copy constructor called" << RESET << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Cure copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure(void)
{
	std::cout << DESTRUCTOR_COLOR << "Cure destructor called" << RESET << std::endl;
}

AMateria	*Cure::clone() const
{
	AMateria	*newCure = new Cure(*this);
	return newCure;
}

void	Cure::use(ICharacter &target)
{
	std::cout << USE_COLOR << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
