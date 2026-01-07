/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:24:14 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 13:09:57 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) 
{
	std::cout << "Created a HumanA named " << _name << "." << std::endl;
	std::cout << "HumanA " << _name << " is holding " << _weapon.getType() << "." << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "The HumanA " << _name << " was erased from existance." << std::endl;
	return ;
};

void	HumanA::attack(void)
{
	std::cout << _name << " attacks whit their " << _weapon.getType() << std::endl;
}