/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:23:45 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/20 12:50:52 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *Horde = zombieHorde(4, "Carlos");
	int i = 0;
	while (i < 4)
	{
		std::cout << i << " ";
		Horde[i].announce();
		i++;
	}
	delete[] Horde;
	return 0;
}