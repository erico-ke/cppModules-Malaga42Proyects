/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:14:21 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/01 12:50:37 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(void): _name("Unnamed AForm"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Default AForm constructor called" << RESET);
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade): _name(name),
	_isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "AForm constructor called for " << _name << RESET);
	if (_signGrade < 1 || _executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other): _name(other._name), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "AForm copy constructor called" << RESET);
}

AForm &AForm::operator=(const AForm &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "AForm copy assignment operator called" << RESET);
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "AForm destructor called for " << _name << RESET);
}

const std::string	&AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade too high.");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade too low.");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed, unable to execute.");
}

void	AForm::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() > _signGrade)
		throw AForm::GradeTooHighException();
	_isSigned = true;
}
// CHECK THIS PLEASE, NOT SURE IF IT's OK
void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
	if (_isSigned == 0)
		throw AForm::FormNotSignedException();
	this->executeAction();
}

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << "AForm '" << src.getName() << "', signed: " << src.getIsSigned()
		<< ", sign grade: " << src.getSignGrade()
		<< ", execute grade: " << src.getExecuteGrade() << ".";
	return (out);
}
