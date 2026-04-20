/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:25:09 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/20 18:58:31 by erico-ke         ###   ########.fr       */
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
	_recursiveSort(newLarger);
	_insertionPhase(newLarger, newSmaller, oddElem);

	larger.clear();
	for (size_t i = 0; i < newLarger.size(); ++i)
		larger.push_back(newLarger[i]);
}

template<typename Container>
void PmergeMe<Container>::_insertionPhase(Container &sorted, const Container &smaller, int oddElement)
{
	std::vector<int>	jacobsthal = _generateJacobsthal(smaller.size());

	std::vector<int>	gaps;
	for (size_t i = 2; i < jacobsthal.size(); ++i)
	{
		int gap = jacobsthal[i] - jacobsthal[i - 1];
		if (gap > 0 && gap <= (int)smaller.size())
			gaps.push_back(gap);
	}

	std::vector<bool> inserted(smaller.size(), false);

	for (size_t g = 0; g < gaps.size(); ++g)
	{
		int gap = gaps[g];
		for (int j = gap; j > 0 && j <= (int)smaller.size(); --j)
		{
			if (!inserted[j - 1])
			{
				typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.begin() + std::min((int)sorted.size(), j + 1), smaller[j - 1]);
				sorted.insert(it, smaller[j - 1]);
				inserted[j - 1] = true;
			}
		}
	}
	
	for (size_t i = 0; i < smaller.size(); ++i)
	{
		if (!inserted[i])
		{
			typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), smaller[i]);
			sorted.insert(it, smaller[i]);
		}
	}

	if (oddElement != -1)
		sorted.push_back(oddElement);
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
	_recursiveSort(larger);
	_insertionPhase(larger, smaller, oddElement);

	data.clear();
	for (size_t i = 0; i < larger.size(); ++i)
		data.push_back(larger[i]);
}

template class PmergeMe<std::deque<int> >;
template class PmergeMe<std::vector<int> >;

