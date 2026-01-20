/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:23:48 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/20 12:52:17 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void): name("Unnamed")
{
}

Zombie::Zombie(std::string zName) : name(zName)
{
}

Zombie::~Zombie()
{
    std::cout << name << " was erased from existance." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setname(std::string name)
{
    this->name = name;
}