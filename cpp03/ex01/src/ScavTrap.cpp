/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:17:03 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/27 17:28:35 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CONSTRUCTOR_COLOR << "Default ScavTrap constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_name = name;
	std::cout << CONSTRUCTOR_COLOR << "ScavTrap constructor called. Generating " << _name << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << CONSTRUCTOR_COLOR << "ScavTrap copy constructor called on " << other._name << RESET << std::endl;
	*this = other;
}


