/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:10:20 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/19 15:56:14 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Unnamed_clap_name"), ScavTrap(), FragTrap(), _name("Unnamed")
{
	ClapTrap::_name = "Unnamed_clap_name";
	
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = 50;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << CONSTRUCTOR_COLOR << "DiamondTrap default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),  ScavTrap(name), FragTrap(name), _name(name)
{
	ClapTrap::_name = name + "_clap_name";
	
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = 50;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << CONSTRUCTOR_COLOR << "DiamondTrap constructor called. Generating " << _name << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << CONSTRUCTOR_COLOR << "DiamondTrap copy constructor called on " << other._name << RESET << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << DESTRUCTOR_COLOR << "DiamondTrap destructor called for " << _name << RESET << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << CONSTRUCTOR_COLOR << "DiamondTrap copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << WHOAMI_COLOR << "I am DiamondTrap " << _name << " and my ClapTrap name is " << ClapTrap::_name << RESET << std::endl;
}