/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:45:34 by erico-ke          #+#    #+#             */
/*   Updated: 2025/12/16 00:00:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

Contact::~Contact() {}

// Setters
void	Contact::setFirstName(const std::string& firstName) {
	this->firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName) {
	this->lastName = lastName;
}

void	Contact::setNickname(const std::string& nickname) {
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret) {
	this->darkestSecret = darkestSecret;
}

// Getters
std::string	Contact::getFirstName() const {
	return this->firstName;
}

std::string	Contact::getLastName() const {
	return this->lastName;
}

std::string	Contact::getNickname() const {
	return this->nickname;
}

std::string	Contact::getPhoneNumber() const {
	return this->phoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return this->darkestSecret;
}

bool	Contact::isEmpty() const {
	return (firstName.empty());
}
