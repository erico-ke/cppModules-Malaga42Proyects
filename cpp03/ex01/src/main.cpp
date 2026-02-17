/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:36:47 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/17 16:08:19 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int	main(void)
{
	{
		std::cout << "[SCAVTRAP STATS CHECK]" << std::endl;
		ScavTrap one = ScavTrap("Stats check");
		std::cout << one.getName() << " has " << one.getHitPoints() << " hit points." << std::endl;
		std::cout << one.getName() << " has " << one.getEnergyPoints() << " energy points." << std::endl;
		std::cout << one.getName() << " has " << one.getAttackDamage() << " attack damage." << std::endl;
	}
	std::cout << std::endl;
	{	
		std::cout << "[SCAVTRAP FUNCTIONS CHECK]" << std::endl;
		ScavTrap one = ScavTrap();
		ScavTrap two = ScavTrap("Finneption");
		one.guardGate();
		two.attack("Unnamed");
		one.takeDamage(20);
		std::cout << "Unnamed has " << one.getHitPoints() << " hit points left." << std::endl;
		std::cout << "Finneption has " << two.getEnergyPoints() << " energy points left." << std::endl;
		one.beRepaired(5);
		std::cout << "Unnamed has " << one.getHitPoints() << " hit points left." << std::endl;
	}
}
