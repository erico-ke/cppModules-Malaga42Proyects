/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:45:58 by erico-ke          #+#    #+#             */
/*   Updated: 2025/09/30 13:05:21 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		Contact();
		~Contact();
		
		// Setters
		void	setFirstName(const std::string& firstName);
		void	setLastName(const std::string& lastName);
		void	setNickname(const std::string& nickname);
		void	setPhoneNumber(const std::string& phoneNumber);
		void	setDarkestSecret(const std::string& darkestSecret);
		
		// Getters
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
		
		bool	isEmpty() const;
};

#endif