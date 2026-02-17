/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:36:44 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/27 16:45:44 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << CONSTRUCTOR_COLOR << "Default ClapTrap constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << CONSTRUCTOR_COLOR << "ClapTrap constructor called. Generating " << _name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << CONSTRUCTOR_COLOR << "ClapTrap copy constructor called on " << other._name << RESET << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << DESTRUCTOR_COLOR << "ClapTrap destructor called" << RESET << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << CONSTRUCTOR_COLOR << "ClapTrap copy assignment operator called" << RESET << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "ClapTrap " << _name << " can not attack, no hit points left." << RESET << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "ClapTrap " << _name << " can not attack, no energy points left." << RESET << std::endl;
		return ;
	}
	std::cout << ATTACK_COLOR << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage." << RESET << std::endl;
	_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "ClapTrap " << _name << " can not be damaged, no hit points left." << RESET << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << DAMAGE_COLOR << "ClapTrap " << _name << " takes " << amount << " points of damage, it has " << _hitPoints << " hit points left." << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "ClapTrap " << _name << " can not repair itself, no hit points left." << RESET << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "ClapTrap " << _name << " can not repair itself, no energy points left." << RESET << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout << HEAL_COLOR << "ClapTrap " << _name << " heals itself by " << amount << " hit points." << RESET << std::endl;
}

std::string	ClapTrap::getName(void)
{
	return _name;
}

int	ClapTrap::getHitPoints(void)
{
	return _hitPoints;	
}

int	ClapTrap::getEnergyPoints(void)
{
	return _energyPoints;
}

int	ClapTrap::getAttackDamage(void)
{
	return _attackDamage;
}

void	ClapTrap::setHitpoints(unsigned int Hp)
{
	_hitPoints = Hp;
}

void	ClapTrap::setEnergyPoints(unsigned int Ep)
{
	_energyPoints = Ep;
}

void	ClapTrap::setAttackDamage(unsigned int Ad)
{
	_attackDamage = Ad;
}
