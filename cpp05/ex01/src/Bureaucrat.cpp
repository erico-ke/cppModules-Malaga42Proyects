/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:48:15 by erico-ke          #+#    #+#             */
/*   Updated: 2026/03/31 18:10:07 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Unnamed"), _grade(150)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Default Bureaucrat constructor called" << RESET);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Bureaucrat constructor called" << RESET);
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Bureaucrat copy constructor called" << RESET);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Bureaucrat copy assignment operator called" << RESET);
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "Bureaucrat destructor called for " << _name << RESET);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too low.");
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (out);
}