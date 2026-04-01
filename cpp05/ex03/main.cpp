/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:54:43 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/01 14:35:09 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/Intern.hpp"

int	main(void)
{
	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	AForm		*form;

	form = intern.makeForm("robotomy request", "Bender");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
	try
	{
		form = intern.makeForm("no existe", "target");
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}