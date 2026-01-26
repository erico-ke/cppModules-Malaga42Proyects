/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:36:47 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/26 17:28:49 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int	main(void)
{
	ClapTrap one = ClapTrap("Finn");
	ClapTrap two = ClapTrap();
	one.attack(two.getName());
	two.takeDamage(10);
	two.beRepaired(5);
	two.attack(one.getName());
	two = one;
	two.takeDamage(5);
	two.beRepaired(5);
	ClapTrap four(one);
	int i = -1;
	while (++i < 10)
		four.attack(one.getName());
	return 0;
}