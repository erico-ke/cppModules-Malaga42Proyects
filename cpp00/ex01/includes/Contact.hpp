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

class Contact {
	private:
		std::string	name;
		std::string	surname;
		int			phone_nbr;
		std::string	darkest_secret;
	public:
		Contact(std::string name, std::string surname, int phone_nbr, std::string darkest_secret);
		Contact();
		~Contact();
};

#endif