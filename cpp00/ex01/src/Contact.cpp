/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:45:34 by erico-ke          #+#    #+#             */
/*   Updated: 2025/09/30 13:35:09 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/Contact.hpp"

Contact::Contact(std::string name, std::string surname, int phone_nbr, std::string darkest_secret){
	this->name = name;
	this->surname = surname;
	this->phone_nbr = phone_nbr;
	this->darkest_secret = darkest_secret;
}

Contact::Contact(){}

Contact::~Contact(){}
