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

class Phonebook {
	private:
		Contact contacts[8];
	public:
		Phonebook();
		int		check_input(std::string input, Phonebook phbk);
		void	display_contact(Phonebook phbk);
		void	add_contact(Phonebook phbk);
		~Phonebook();
};

#endif