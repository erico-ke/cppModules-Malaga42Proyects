/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:49:27 by erico-ke          #+#    #+#             */
/*   Updated: 2025/09/30 10:19:30 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
	if (!argv[1])
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i != argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (isalpha(argv[i][j]))
				std::cout << (char)toupper(argv[i][j]);
			else
				std::cout << argv[i][j];
		}
		if (i != argc - 1)
			std:: cout << " ";
	}
	std::cout << std::endl;
	return (0);
}