/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:24:16 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 12:43:25 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

using std::cout;
using std::endl;

HumanB::HumanB(void)
{
	_name = "unnamed";
	cout << "Created a HumanB named " << _name << "." << endl;
	return ;
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	cout << "Created a HumanB named " << _name << "." << endl;
	return ;
}

HumanB::~HumanB(void)
{
	cout << "The HumanB " << _name << " was erased from existance." << endl;
	return ;
};

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
	cout << "HumanB " << _name << " is holding " << _weapon->getType() << "." << endl;
}

void	HumanB::attack(void)
{
	if (_weapon)
		cout << _name << " attacks with their " << _weapon->getType() << endl;
	else
		cout << _name << " attacks with their bare hands" << endl;
}