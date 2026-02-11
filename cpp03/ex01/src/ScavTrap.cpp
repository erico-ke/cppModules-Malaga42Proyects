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

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << CONSTRUCTOR_COLOR << "ScavTrap copy constructor called on " << other._name << RESET << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << DESTRUCTOR_COLOR << "ScavTrap destructor called" << RESET << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << CONSTRUCTOR_COLOR << "ScavTrap copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "ScavTrap " << _name << " can not attack, no hit points left." << RESET << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "ScavTrap " << _name << " can not attack, no energy points left." << RESET << std::endl;
		return ;
	}
	std::cout << ATTACK_COLOR << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage." << RESET << std::endl;
	_energyPoints -= 1;
}

void	ScavTrap::guardGate(void)
{
	std::cout << HEAL_COLOR << "ScavTrap " << _name << " is now in Gate keeper mode." << RESET << std::endl;
}

int	ScavTrap::getHitPoints(void)
{
	return _hitPoints;
}

int	ScavTrap::getEnergyPoints(void)
{
	return _energyPoints;
}

int	ScavTrap::getAttackDamage(void)
{
	return _attackDamage;
}

std::string	ScavTrap::getName(void)
{
	return _name;
}