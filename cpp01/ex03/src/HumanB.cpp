/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:24:16 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 13:10:45 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(void)
{
	_name = "unnamed";
	std::cout << "Created a HumanB named " << _name << "." << std::endl;
	return ;
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << "Created a HumanB named " << _name << "." << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "The HumanB " << _name << " was erased from existance." << std::endl;
	return ;
};

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
	std::cout << "HumanB " << _name << " is holding " << _weapon->getType() << "." << std::endl;
}

void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their bare hands" << std::endl;
}