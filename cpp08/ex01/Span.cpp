/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:12:07 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/09 19:10:14 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

const char	*Span::NotEnoughSpace::what() const throw()
{
	return "Error: Span is full, cannot add more numbers";
}

Span::Span(void) : _N(0)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Default Span constructor called" << RESET);
	_numbers.reserve(0);
}

Span::Span(unsigned int N) : _N(N)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Span constructor called with N=" << N << RESET);
	_numbers.reserve(N);
}

Span::Span(const Span &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Span copy constructor called" << RESET);
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "Span copy assignment operator called" << RESET);
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "Span destructor called" << RESET);
}

void	Span::addNumber(int num)
{
	if (_numbers.size() >= _N)
		throw NotEnoughSpace();
	_numbers.push_back(num);
	DEBUG_LOG("Added number " << num );
}

int	Span::shortestSpan(void) const
{
	if (_numbers.size() <  2)
		throw std::logic_error("Error: Cannot calculate span with less than 2 numbers");
	
	std::vector<int> sorted_numbers = _numbers;
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	int min_span = sorted_numbers[1] - sorted_numbers[0];
	for (size_t i = 2; i < sorted_numbers.size(); ++i)
	{
		int span = sorted_numbers[i] - sorted_numbers[i - 1];
		if (span < min_span)
			min_span = span;
	}
	DEBUG_LOG("Shortest span calculated: " << min_span);
	return min_span;
}

int	Span::longuestSpan(void) const
{
	if (_numbers.size() <  2)
		throw std::logic_error("Error: Cannot calculate span with less than 2 numbers");
	
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
		
	int longuest = max - min;
	DEBUG_LOG("Longuest span calculated: " << longuest);
	return longuest;
}

unsigned int Span::getN(void) const
{
	return _N;
}

unsigned int Span::getSize(void) const
{
	return _numbers.size();
}