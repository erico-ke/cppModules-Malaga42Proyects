/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:13:19 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/18 18:03:18 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << CONSTRUCTOR_COLOR << "Default FragTrap constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_name = name;
	std::cout << CONSTRUCTOR_COLOR << "FragTrap constructor called. Generating " << _name << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << CONSTRUCTOR_COLOR << "FragTrap copy constructor called on " << other._name << RESET << std::endl;
	*this = other;
}

FragTrap::~FragTrap(void)
{
	std::cout << DESTRUCTOR_COLOR << "FragTrap destructor called" << RESET << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << CONSTRUCTOR_COLOR << "FragTrap copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

void	FragTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "FragTrap " << _name << " can not attack, no hit points left." << RESET << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "FragTrap " << _name << " can not attack, no energy points left." << RESET << std::endl;
		return ;
	}
	std::cout << ATTACK_COLOR << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage." << RESET << std::endl;
	_energyPoints -= 1;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "FragTrap " << _name << " can not be damaged, no hit points left." << RESET << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << DAMAGE_COLOR << "FragTrap " << _name << " takes " << amount << " points of damage, it has " << _hitPoints << " hit points left." << RESET << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "FragTrap " << _name << " can not repair itself, no hit points left." << RESET << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "FragTrap " << _name << " can not repair itself, no energy points left." << RESET << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout << HEAL_COLOR << "FragTrap " << _name << " heals itself by " << amount << " hit points." << RESET << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << HIGHFIVE_COLOR << _name << ": Ey guys do you want a high five?\n\t" << WHAMM_COLOR << "*WHAMM*" << RESET << HIGHFIVE_COLOR << "\nHere you go." << RESET << std::endl;
}

int	FragTrap::getHitPoints(void)
{
	return _hitPoints;
}

int	FragTrap::getEnergyPoints(void)
{
	return _energyPoints;
}

int	FragTrap::getAttackDamage(void)
{
	return _attackDamage;
}

std::string	FragTrap::getName(void)
{
	return _name;
}
