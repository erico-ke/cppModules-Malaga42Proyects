/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:00:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/08 11:00:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Base.hpp"

int	main(void)
{
	for (int i = 0; i < 10; i++)
	{
		Base *instance = generate();
		std::cout << "identify(Base*): ";
		identify(instance);
		std::cout << "identify(Base&): ";
		identify(*instance);
		delete instance;
	}
	return (0);
}