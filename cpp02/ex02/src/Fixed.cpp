/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:45:40 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/20 10:36:39 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointNumber = num <<  _fractionalBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointNumber = roundf(num * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointNumber = other._fixedPointNumber;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointNumber;
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointNumber = raw;
}

float	Fixed::toFloat(void) const
{
	return  static_cast<float>(_fixedPointNumber) / (1 << _fractionalBits);
}

int		Fixed::toInt(void) const
{
	return _fixedPointNumber / (1 << _fractionalBits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool	Fixed::operator>(const Fixed &other) const
{
	return _fixedPointNumber > other._fixedPointNumber;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return _fixedPointNumber < other._fixedPointNumber;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return _fixedPointNumber >= other._fixedPointNumber;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return _fixedPointNumber <= other._fixedPointNumber;
}

bool	Fixed::operator==(const Fixed &other) const
{
	return _fixedPointNumber == other._fixedPointNumber;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return _fixedPointNumber != other._fixedPointNumber;
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return	Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other.toFloat() == 0)
	{
		std::cout << "Error: dividing by 0 is forbidden" << std::endl;
		return (-1);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++()
{
	_fixedPointNumber++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);
	_fixedPointNumber++;
	return ret;
}

Fixed	&Fixed::operator--()
{
	_fixedPointNumber--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);
	_fixedPointNumber--;
	return ret;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
