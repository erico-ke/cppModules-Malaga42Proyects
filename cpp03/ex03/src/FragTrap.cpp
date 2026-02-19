/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:13:19 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/19 14:28:17 by erico-ke         ###   ########.fr       */
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
	_energyPoints = 100;
	_attackDamage = 30;
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

void	FragTrap::highFivesGuys(void)
{
	if (_hitPoints <= 0)
	{
		std::cout << DAMAGE_COLOR << "FragTrap " << _name << " can not give high fives, no hit points left." << RESET << std::endl;
		return ;
	}
	std::cout << HIGHFIVE_COLOR << "FragTrap " << _name << ": Ey guys do you want a high five?\n\t" << WHAMM_COLOR << "*WHAMM*" << RESET << HIGHFIVE_COLOR << "\nHere you go." << RESET << std::endl;
}
