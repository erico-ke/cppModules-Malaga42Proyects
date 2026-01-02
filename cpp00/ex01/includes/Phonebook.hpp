/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:46:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/02 17:08:43 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>

class Phonebook {
	private:
		Contact contacts[8];
		int		contactCount;
		int		oldestIndex;
	public:
		Phonebook();
		~Phonebook();
		void	addContact();
		void	searchContact();
		void	displayAllContacts();
		void	displayContactDetails(int index);
		std::string	truncate(std::string str, size_t width);
		size_t	getDisplayWidth(const std::string& str);
		std::string	formatField(const std::string& str, size_t width);
		bool	isOnlyWhitespace(const std::string& str);
		std::string	trim(const std::string& str);
};

#endif