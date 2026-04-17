/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 14:55:43 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/17 11:48:15 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << ERROR_COLOR << "Error: invalid amount of arguments." << RESET << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc;
		btc.loadDatabase("data.csv");
		btc.processInput(argv[1]);
	}
	catch (const BitcoinExchangeException& e)
	{
		std::cerr << ERROR_COLOR << e.what() << RESET << std::endl;
		return 1;
	}
	catch (const std::exception& e)
	{
		std::cerr << ERROR_COLOR << "Unexpected error: " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}

