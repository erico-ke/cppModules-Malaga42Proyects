/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:24:22 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 12:50:35 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

using std::cout;
using std::endl;

Weapon::Weapon(std::string typ)
{
	cout << "Created a weapon." << endl;
	setType(typ);
	return ;
}

Weapon::~Weapon(void)
{
	cout << "Destroyed a weapon with type: " << _type << "." << endl;
	return ;
}

std::string const &Weapon::getType(void)
{
    return _type;
}

void    Weapon::setType(std::string type)
{
    _type = type;
	cout << "Weapon type setted to: " << _type << "." << endl;
    return ;
}
