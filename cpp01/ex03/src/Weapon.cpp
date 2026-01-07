/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:24:22 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 13:11:30 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string typ)
{
	std::cout << "Created a weapon." << std::endl;
	setType(typ);
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Destroyed a weapon with type: " << _type << "." << std::endl;
	return ;
}

std::string const &Weapon::getType(void)
{
    return _type;
}

void    Weapon::setType(std::string type)
{
    _type = type;
	std::cout << "Weapon type setted to: " << _type << "." << std::endl;
    return ;
}
