/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:46:00 by erico-ke          #+#    #+#             */
/*   Updated: 2025/09/30 14:21:05 by erico-ke         ###   ########.fr       */
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
};

#endif