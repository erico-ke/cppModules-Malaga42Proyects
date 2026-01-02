/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:09:53 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/02 17:08:43 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

int	main(void) {
	Phonebook phonebook;
	std::string input;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		
		if (std::cin.eof()) {
			std::cout << std::endl;
			break;
		}

		if (input == "ADD") {
			phonebook.addContact();
		} else if (input == "SEARCH") {
			phonebook.searchContact();
		} else if (input == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
		}
	}
	return (0);
}
