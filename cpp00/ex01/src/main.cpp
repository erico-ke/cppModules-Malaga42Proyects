/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:09:53 by erico-ke          #+#    #+#             */
/*   Updated: 2025/09/30 13:41:52 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

int	main(void){
	Phonebook phbk;
	std::string input;
	while (1){
		std::cout << "Insert 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
		getline(std::cin, input);
		if (phbk.check_input(input) == 3)
			break ;
	}
	return (0);
}