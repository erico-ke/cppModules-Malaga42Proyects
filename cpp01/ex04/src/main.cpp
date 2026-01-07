/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:15:05 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 15:18:35 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sedIsForLosers.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: wrong input ammount. try ./sedIsForLosers filename string1 string2" << std::endl;
		return 1;
	}
	std::string	filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	try {
		std::string	file_content = readFileContent(filename);
		replaceFileContent(file_content, s1, s2);
		writeFileContent(filename, file_content);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}