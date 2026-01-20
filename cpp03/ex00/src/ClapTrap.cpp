/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:36:44 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/20 14:53:59 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unnamed")
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "ClapTrap constructor called. Generating " << _name << std::endl;
}



ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}