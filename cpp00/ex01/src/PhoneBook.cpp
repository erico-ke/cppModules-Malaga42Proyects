/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:45:22 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/02 17:09:09 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

Phonebook::Phonebook() : contactCount(0), oldestIndex(0) {}

Phonebook::~Phonebook() {}

size_t	Phonebook::getDisplayWidth(const std::string& str) {
	size_t width = 0;
	size_t i = 0;
	while (i < str.length()) {
		unsigned char c = str[i];
		if (c < 0x80) {
			width++;
			i++;
		} else if ((c & 0xE0) == 0xC0) {
			width++;
			i += 2;
		} else if ((c & 0xF0) == 0xE0) {
			width++;
			i += 3;
		} else if ((c & 0xF8) == 0xF0) {
			width++;
			i += 4;
		} else {
			width++;
			i++;
		}
	}
	return width;
}

std::string	Phonebook::truncate(std::string str, size_t width) {
	if (getDisplayWidth(str) > width) {
		size_t displayWidth = 0;
		size_t bytePos = 0;
		while (bytePos < str.length() && displayWidth < width - 1) {
			unsigned char c = str[bytePos];
			if (c < 0x80) {
				bytePos++;
			} else if ((c & 0xE0) == 0xC0) {
				bytePos += 2;
			} else if ((c & 0xF0) == 0xE0) {
				bytePos += 3;
			} else if ((c & 0xF8) == 0xF0) {
				bytePos += 4;
			} else {
				bytePos++;
			}
			displayWidth++;
		}
		return str.substr(0, bytePos) + ".";
	}
	return str;
}

bool	Phonebook::isOnlyWhitespace(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isspace(str[i])) {
			return false;
		}
	}
	return true;
}

std::string	Phonebook::trim(const std::string& str) {
	size_t start = 0;
	size_t end = str.length();
	
	while (start < end && std::isspace(str[start])) {
		start++;
	}
	
	while (end > start && std::isspace(str[end - 1])) {
		end--;
	}
	
	return str.substr(start, end - start);
}

void	Phonebook::addContact() {
	Contact newContact;
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	input = trim(input);
	if (input.empty() || std::cin.eof() || isOnlyWhitespace(input)) {
		std::cout << "First name cannot be empty!" << std::endl;
		return;
	}
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	input = trim(input);
	if (input.empty() || std::cin.eof() || isOnlyWhitespace(input)) {
		std::cout << "Last name cannot be empty!" << std::endl;
		return;
	}
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	input = trim(input);
	if (input.empty() || std::cin.eof() || isOnlyWhitespace(input)) {
		std::cout << "Nickname cannot be empty!" << std::endl;
		return;
	}
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	input = trim(input);
	if (input.empty() || std::cin.eof()) {
		std::cout << "Phone number cannot be empty!" << std::endl;
		return;
	}
	for (size_t i = 0; i < input.length(); i++) {
		if (!std::isdigit(input[i])) {
			std::cout << "Phone number must contain only digits!" << std::endl;
			return;
		}
	}
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	input = trim(input);
	if (input.empty() || std::cin.eof() || isOnlyWhitespace(input)) {
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

std::string	Phonebook::formatField(const std::string& str, size_t width) {
	std::string truncated = truncate(str, width);
	size_t displayWidth = getDisplayWidth(truncated);
	size_t padding = width > displayWidth ? width - displayWidth : 0;
	return std::string(padding, ' ') + truncated;
}

void	Phonebook::displayAllContacts() {
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < contactCount; i++) {
		if (!contacts[i].isEmpty()) {
			std::cout << std::setw(10) << std::right << i << "|";
			std::cout << formatField(contacts[i].getFirstName(), 10) << "|";
			std::cout << formatField(contacts[i].getLastName(), 10) << "|";
			std::cout << formatField(contacts[i].getNickname(), 10) << "|" << std::endl;
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
		std::cout << std::endl;
		exit(0);
	}

	
	char* endptr;
	index = std::strtol(input.c_str(), &endptr, 10);
	
	if (*endptr != '\0' || endptr == input.c_str()) {
		std::cout << "Invalid input!" << std::endl;
		return;
	}

	displayContactDetails(index);
}
