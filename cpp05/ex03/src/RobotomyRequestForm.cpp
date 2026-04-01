/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:18:15 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/01 13:27:04 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyRequestForm:" + target, 72, 45), _target(target)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "RobotomyRequestForm constructor called for " << getName() << RESET);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm(other), _target(other._target)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "RobotomyRequestForm copy constructor called" << RESET);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "RobotomyRequestForm copy assignment operator called" << RESET);
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "RobotomyRequestForm destructor called for " << getName() << RESET);
}

const std::string	&RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::executeAction(void) const
{
	static bool	seeded = false;

	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	std::cout << "BZZZZZZ... DRRRRRRRR..." << std::endl;
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed for " << getTarget() << "." << std::endl;
}
