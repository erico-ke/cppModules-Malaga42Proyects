/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:12:47 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/18 15:59:54 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl created" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl destroyed" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(int level)
{
	switch (level)
	{
	case 1:
		std::cout << "[ DEBUG ]" << std::endl;
		Harl::debug();
		std::cout << std::endl;
	case 2:
		std::cout << "[ INFO ]" << std::endl;
		Harl::info();
		std::cout << std::endl;
	case 3:
		std::cout << "[ WARNING ]" << std::endl;
		Harl::warning();
		std::cout << std::endl;
	case 4:
		std::cout << "[ ERROR ]" << std::endl;
		Harl::error();
		std::cout << std::endl;
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break ;
	}
}