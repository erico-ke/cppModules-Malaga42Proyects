/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:45:22 by erico-ke          #+#    #+#             */
/*   Updated: 2025/12/16 00:00:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

Phonebook::Phonebook() : contactCount(0), oldestIndex(0) {}

Phonebook::~Phonebook() {}

std::string	Phonebook::truncate(std::string str, size_t width) {
	if (str.length() > width) {
		return str.substr(0, width - 1) + ".";
	}
	return str;
}

void	Phonebook::addContact() {
	Contact newContact;
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (input.empty() || std::cin.eof()) {
		std::cout << "First name cannot be empty!" << std::endl;
		return;
	}
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (input.empty() || std::cin.eof()) {
		std::cout << "Last name cannot be empty!" << std::endl;
		return;
	}
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (input.empty() || std::cin.eof()) {
		std::cout << "Nickname cannot be empty!" << std::endl;
		return;
	}
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	if (input.empty() || std::cin.eof()) {
		std::cout << "Phone number cannot be empty!" << std::endl;
		return;
	}
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty() || std::cin.eof()) {
		std::cout << "Darkest secret cannot be empty!" << std::endl;
		return;
	}
	newContact.setDarkestSecret(input);


	if (contactCount < 8) {
		contacts[contactCount] = newContact;
		contactCount++;
	} else {
		contacts[oldestIndex] = newContact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

void	Phonebook::displayAllContacts() {
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < contactCount; i++) {
		if (!contacts[i].isEmpty()) {
			std::cout << std::setw(10) << std::right << i << "|";
			std::cout << std::setw(10) << std::right << truncate(contacts[i].getFirstName(), 10) << "|";
			std::cout << std::setw(10) << std::right << truncate(contacts[i].getLastName(), 10) << "|";
			std::cout << std::setw(10) << std::right << truncate(contacts[i].getNickname(), 10) << std::endl;
		}
	}
}

void	Phonebook::displayContactDetails(int index) {
	if (index < 0 || index >= contactCount || contacts[index].isEmpty()) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void	Phonebook::searchContact() {
	std::string input;
	int index;

	if (contactCount == 0) {
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}

	displayAllContacts();
	std::cout << "Enter index of contact to display: ";
	std::getline(std::cin, input);
	
	if (std::cin.eof()) {
		return;
	}

	
	char* endptr;
	index = std::strtol(input.c_str(), &endptr, 10);
	
	if (*endptr != '\0' || endptr == input.c_str()) {
		std::cout << "Invalid input!" << std::endl;
		return;
	}

	displayContactDetails(index);
}
