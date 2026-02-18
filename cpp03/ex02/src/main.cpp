/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:36:47 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/18 18:02:20 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"

int	main(void)
{
	{
		std::cout << "[FRAGTRAP STATS CHECK]" << std::endl;
		FragTrap one = FragTrap("CheckMe");
		std::cout << one.getName() << " has " << one.getHitPoints() << " hit points." << std::endl;
		std::cout << one.getName() << " has " << one.getEnergyPoints() << " energy points." << std::endl;
		std::cout << one.getName() << " has " << one.getAttackDamage() << " attack damage." << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "[FRAGTRAP FUNCTIONS CHECK]" << std::endl;
		FragTrap one = FragTrap();
		FragTrap two = FragTrap("ClimateChange");
		two.highFivesGuys();
		one.attack("ClimateChange");
		two.takeDamage(30);
		two.beRepaired(12);
		std::cout << two.getName() << " has " << two.getHitPoints() << " hit points." << std::endl;
	}
}
