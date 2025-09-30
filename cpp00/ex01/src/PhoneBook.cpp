/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:45:22 by erico-ke          #+#    #+#             */
/*   Updated: 2025/09/30 14:24:14 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

void	Phonebook::add_contact(Phonebook phbk){
	
}

void	Phonebook::display_contact(Phonebook phbk){
	
}

int Phonebook::check_input(std::string input, Phonebook phbk){
	if (input == "EXIT")
		return (3);
	else if (input == "ADD")
		add_contact();
	else if (input == "SEARCH")
		display_contact();
	else
		std::cout << "Invalid input." << std::endl;
	return (0);
}

Phonebook::Phonebook(){};

Phonebook::~Phonebook(){};