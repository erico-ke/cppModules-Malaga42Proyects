/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:09:18 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/01 14:35:07 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Default Intern constructor called" << RESET);
}

Intern::Intern(const Intern &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Intern copy constructor called" << RESET);
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Intern copy assignment operator called" << RESET);
	(void)other;
	return *this;
}

Intern::~Intern(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "Intern destructor called" << RESET);
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) const
{
	std::string	formArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (formArray[i] == formName)
		{
			switch (i)
			{
				case 0:
					std::cout << "Intern creates " << formName << "." << std::endl;
					return (new ShrubberyCreationForm(target));
				case 1:
					std::cout << "Intern creates " << formName << "." << std::endl;
					return (new RobotomyRequestForm(target));
				case 2:
					std::cout << "Intern creates " << formName << "." << std::endl;
					return (new PresidentialPardonForm(target));
				default:
					break;
			}
		}	
	}
	throw Intern::FormNotFoundException();
}

const char	*Intern::FormNotFoundException::what(void) const throw()
{
	return ("Form format does not match an existant format.");
}
