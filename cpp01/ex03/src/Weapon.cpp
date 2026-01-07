/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:24:22 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 11:24:23 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string typ) : type(typ){return ;}

Weapon::~Weapon(void){return ;}

std::string const &Weapon::getType(void)
{
    return this->type;
}

void    Weapon::setType(std::string type)
{
    this->type = type;
    return ;
}
