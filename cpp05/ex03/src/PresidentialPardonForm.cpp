/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:28:30 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/01 13:31:30 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm:" + target, 25, 5), _target(target)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "PresidentialPardonForm constructor called for " << getName() << RESET);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(other), _target(other._target)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "PresidentialPardonForm copy constructor called" << RESET);
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "PresidentialPardonForm copy assignment operator called" << RESET);
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "PresidentialPardonForm destructor called for " << getName() << RESET);
}

const std::string	&PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::executeAction(void) const
{
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
