/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:24:14 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 12:42:22 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

using std::cout;
using std::endl;

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) 
{
	cout << "Created a HumanA named " << _name << "." << endl;
	cout << "HumanA " << _name << " is holding " << _weapon.getType() << "." << endl;
	return ;
}

HumanA::~HumanA(void)
{
	cout << "The HumanA " << _name << " was erased from existance." << endl;
	return ;
};

void	HumanA::attack(void)
{
	cout << _name << " attacks whit their " << _weapon.getType() << endl;
}