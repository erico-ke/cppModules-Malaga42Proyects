/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:54:43 by erico-ke          #+#    #+#             */
/*   Updated: 2026/03/31 17:02:51 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat alice("Alice", 2);
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << alice << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Alice test failed: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bob("Bob", 149);
		std::cout << bob << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Bob test failed: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat invalidLow("InvalidLow", 151);
		std::cout << invalidLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "InvalidLow test failed: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat invalidHigh("InvalidHigh", 0);
		std::cout << invalidHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "InvalidHigh test failed: " << e.what() << std::endl;
	}
	return (0);
}