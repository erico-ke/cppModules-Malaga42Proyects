/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:14:21 by erico-ke          #+#    #+#             */
/*   Updated: 2026/03/31 18:14:42 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void)
{
	std::cout << CONSTRUCTOR_COLOR << "Default Form constructor called" << RESET << std::endl;
}

Form::Form(const Form &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Form copy constructor called" << RESET << std::endl;
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	std::cout << CONSTRUCTOR_COLOR << "Form copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		
	}
	return *this;
}

Form::~Form(void)
{
	std::cout << DESTRUCTOR_COLOR << "Form destructor called" << RESET << std::endl;
}
