/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:15:47 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/01 12:45:06 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm:" + target, 145, 137), _target(target)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "ShubberyCreationForm constructor called for " << getName() << RESET);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(other), _target(other._target)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "ShubberyCreationForm copy constructor called" << RESET);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "ShubberyCreationForm copy assignment operator called" << RESET);
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "ShubberyCreationForm destructor called for " << getName() << RESET);
}

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

const char	*ShrubberyCreationForm::FailToOpenFile::what() const throw()
{
	return ("ShrubberyCreationForm: failed to create output file");
}

void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	outfile((getTarget() + "_shrubbery").c_str());

	if (!outfile.is_open())
		throw ShrubberyCreationForm::FailToOpenFile();
	outfile << "       _-_," << std::endl;
	outfile << "    /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\ //  ~" << std::endl;
	outfile << "_- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_" << std::endl;
	outfile << "      // \\ " << std::endl;
}