/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:00:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/08 11:00:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::Base(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Base default constructor called" << RESET);
}

Base::Base(const Base &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Base copy constructor called" << RESET);
	(void)other;
}

Base &Base::operator=(const Base &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Base copy assignment operator called" << RESET);
	(void)other;
	return (*this);
}

Base::~Base(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "Base destructor called" << RESET);
}

Base	*generate(void)
{
	static bool	seeded = false;
	int			choice;

	if (!seeded)
	{
		std::srand(std::time(NULL));
		DEBUG_LOG(CONSTRUCTOR_COLOR << "Random seed initialized" << RESET);
		seeded = true;
	}
	choice = std::rand() % 3;
	if (choice == 0)
		return (new A());
	if (choice == 1)
		return (new B());
	return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception &)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception &)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception &)
	{
	}
	std::cout << "Unknown" << std::endl;
}