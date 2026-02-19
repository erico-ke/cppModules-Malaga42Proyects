/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:36:47 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/19 15:57:07 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int	main(void)
{
	{
		std::cout << "[DIAMONDTRAP STATS CHECK]" << std::endl << std::endl;
		DiamondTrap one = DiamondTrap("CheckMe");
		std::cout << std::endl << one.getName() << " has " << one.getHitPoints() << " hit points." << std::endl;
		std::cout << one.getName() << " has " << one.getEnergyPoints() << " energy points." << std::endl;
		std::cout << one.getName() << " has " << one.getAttackDamage() << " attack damage." << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout  << "[DIAMONDTRAP FUNCTIONS CHECK]" << std::endl << std::endl;
		DiamondTrap one = DiamondTrap();
		DiamondTrap two = DiamondTrap("TypicalDiamond");
		std::cout << std::endl;
		one.whoAmI();
		two.whoAmI();
		two.guardGate();
		one.highFivesGuys();
		two.attack("You");
		std::cout << std::endl;
	}
}
