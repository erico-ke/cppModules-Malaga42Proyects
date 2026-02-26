/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:22:39 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 18:47:40 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << CONSTRUCTOR_COLOR << "Default MateriaSource constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_copy[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << CONSTRUCTOR_COLOR << "MateriaSource copy constructor called" << RESET << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << CONSTRUCTOR_COLOR << "MateriaSource copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_copy[i] != NULL)
				delete _copy[i];
			if (other._copy[i] != NULL)
				_copy[i] = other._copy[i]->clone();
			else
				_copy[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << DESTRUCTOR_COLOR << "MateriaSource destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_copy[i] != NULL)
			delete this->_copy[i];
}

void	MateriaSource::learnMateria(AMateria *learn)
{
	for (int i = 0; i < 4; i++)
	{
		if (_copy[i] == NULL)
		{
			std::cout << "Materia " << learn->getType() << " learned." << std::endl;
			_copy[i] = learn;
			return ;
		}
	}
	std::cout << ERROR_COLOR << "Materia " << learn->getType() << " can't be learned" << RESET << std::endl;
	delete learn; 
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_copy[i] && _copy[i]->getType() == type)
		{
			std::cout << "Materia of type " << type << " created" << std::endl;
			return _copy[i]->clone();
		}
	}
	std::cout << ERROR_COLOR << "Materia of type " << type << " can't be created" << RESET << std::endl;
	return 0;
}