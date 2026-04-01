/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:14:21 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/01 10:51:48 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form(void): _name("Unnamed form"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Default Form constructor called" << RESET);
}

Form::Form(const std::string &name, int signGrade, int executeGrade): _name(name),
	_isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Form constructor called for " << _name << RESET);
	if (_signGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other): _name(other._name), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Form copy constructor called" << RESET);
}

Form &Form::operator=(const Form &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Form copy assignment operator called" << RESET);
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "Form destructor called for " << _name << RESET);
}

const std::string	&Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecuteGrade() const
{
	return (_executeGrade);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low.");
}

void	Form::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() > _signGrade)
		throw Form::GradeTooHighException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
	out << "Form '" << src.getName() << "', signed: " << src.getIsSigned()
		<< ", sign grade: " << src.getSignGrade()
		<< ", execute grade: " << src.getExecuteGrade() << ".";
	return (out);
}
