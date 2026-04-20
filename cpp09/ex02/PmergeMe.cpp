/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:25:09 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/20 19:41:28 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

/* ===== PMERGEME EXCEPTIONS BASE ===== */

PmergeMeExceptions::PmergeMeExceptions(void)
	: _message("")
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "PmergeMeExceptions created" << RESET);
}

PmergeMeExceptions::PmergeMeExceptions(const PmergeMeExceptions &other)
	: _message(other._message)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "PmergeMeExceptions copied" << RESET);
}

PmergeMeExceptions &PmergeMeExceptions::operator=(const PmergeMeExceptions &other)
{
	if (this != &other)
		_message = other._message;
	return (*this);
}

PmergeMeExceptions::~PmergeMeExceptions(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "PmergeMeExceptions destroyed" << RESET);
}

const char *PmergeMeExceptions::what(void) const throw()
{
	return (_message.c_str());
}

/* ===== INPUT EXCEPTION ===== */

InputException::InputException(const std::string &invalidArg)
{
	_message = "Error: Invalid input: " + invalidArg;
	DEBUG_LOG(CONSTRUCTOR_COLOR << "InputException created" << RESET);
}

InputException::~InputException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "InputException destroyed" << RESET);
}

/* ===== NEGATIVE NUMBER EXCEPTION ===== */

NegativeNumberException::NegativeNumberException(void)
{
	_message = "Error: Negative number encountered";
	DEBUG_LOG(CONSTRUCTOR_COLOR << "NegativeNumberException created" << RESET);
}

NegativeNumberException::~NegativeNumberException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "NegativeNumberException destroyed" << RESET);
}

/* ===== INVALID SEQUENCE EXCEPTION ===== */

InvalidSequenceException::InvalidSequenceException(const std::string &msg)
{
	_message = "Error: " + msg;
	DEBUG_LOG(CONSTRUCTOR_COLOR << "InvalidSequenceException created" << RESET);
}

InvalidSequenceException::~InvalidSequenceException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "InvalidSequenceException destroyed" << RESET);
}

/* ===== PMERGE ME CLASS ===== */

template<typename Container>
PmergeMe<Container>::PmergeMe(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "PmergeMe default constructor called" << RESET);
}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other)
{
	(void)other;
	DEBUG_LOG(CONSTRUCTOR_COLOR << "PmergeMe copy constructor called" << RESET);
}

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

template<typename Container>
PmergeMe<Container>::~PmergeMe(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "PmergeMe destructor called" << RESET);
}

/* ===== PMERGE ME PRIVATE FUNCTIONS ===== */

template<typename Container>
std::vector<int> PmergeMe<Container>::_generateJacobsthal(int max_value)
{
	std::vector<int>	jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	
	while (jacobsthal.back() < max_value)
	{
		int	size = jacobsthal.size();
		int	next = jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

template<typename Container>
void PmergeMe<Container>::_pairingPhase(Container &input, Container &larger, Container &smailler, int &oddElement)
{
	oddElement = -1;

	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] >  input[i + 1])
		{
			larger.push_back(input[i]);
			smailler.push_back(input[i + 1]);
		}
		else
		{
			larger.push_back(input[i + 1]);
			smailler.push_back(input[i]);
		}
	}
	
	if (input.size() % 2 == 1)
		oddElement = input.back();
}

template<typename Container>
void PmergeMe<Container>::_recursiveSort(Container &larger)
{
	if (larger.size() <= 1)
		return ;
	if (larger.size() == 2)
	{
		if (larger[0] > larger[1])
			std::swap(larger[0], larger[1]);
		return ;
	}

	Container newLarger, newSmaller;
	int oddElem = -1;

	_pairingPhase(larger, newLarger, newSmaller, oddElem);
	Container partners = newLarger;
	_recursiveSort(newLarger);
	_insertionPhase(newLarger, newSmaller, partners, oddElem);

	larger.clear();
	for (size_t i = 0; i < newLarger.size(); ++i)
		larger.push_back(newLarger[i]);
}

template<typename Container>
void PmergeMe<Container>::_insertionPhase(Container &sorted, const Container &smaller, const Container &partners, int oddElement)
{
	size_t n = smaller.size();
	std::vector<size_t> order;

	if (n > 0)
		order.push_back(0);

	std::vector<int> jacobsthal = _generateJacobsthal(static_cast<int>(n));
	size_t previous = 1;

	for (size_t i = 3; i < jacobsthal.size(); ++i)
	{
		size_t current = static_cast<size_t>(jacobsthal[i]);
		if (current > n)
			current = n;
		if (current <= previous)
			continue;
		for (size_t idx = current; idx > previous; --idx)
			order.push_back(idx - 1);
		previous = current;
		if (previous == n)
			break;
	}

	for (size_t idx = n; idx > previous; --idx)
		order.push_back(idx - 1);

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t i = order[k];
		int value = smaller[i];
		int partner = partners[i];
		typename Container::iterator partnerIt = std::find(sorted.begin(), sorted.end(), partner);
		typename Container::iterator searchEnd = (partnerIt != sorted.end()) ? partnerIt : sorted.end();
		typename Container::iterator it = std::lower_bound(sorted.begin(), searchEnd, value);
		sorted.insert(it, value);
	}

	if (oddElement != -1)
	{
		typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), oddElement);
		sorted.insert(it, oddElement);
	}
}

/* ===== PMERGE ME PUBLIC FUNCTIONS ===== */

template<typename Container>
void PmergeMe<Container>::sort(Container &data)
{
	if (data.size() <= 1)
		return ;
		
	Container larger, smaller;
	int	oddElement = -1;
	
	_pairingPhase(data, larger, smaller, oddElement);
	Container partners = larger;
	_recursiveSort(larger);
	_insertionPhase(larger, smaller, partners, oddElement);

	data.clear();
	for (size_t i = 0; i < larger.size(); ++i)
		data.push_back(larger[i]);
}

template class PmergeMe<std::deque<int> >;
template class PmergeMe<std::vector<int> >;

/* ===== PARSER ===== */

void	parseInput(char **input)
{
	int	i = 0;

	while (input[++i])
	{
		int j = -1;
		while (input[i][++j])
			if (!std::isdigit(input[i][j]))
				throw InputException(input[i]);
		long value = std::strtol(input[i], NULL, 10);
		if (value < 0)
			throw NegativeNumberException();
	}
}

