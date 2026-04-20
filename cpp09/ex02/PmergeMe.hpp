/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 14:56:36 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/20 19:41:28 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <algorithm>
# include <iostream>

/* ===== DEBUG MODE ===== */
# ifndef DEBUG
#  define DEBUG 0
# endif

# if DEBUG == 1
#  define DEBUG_LOG(msg) do { std::cout << msg << std::endl; } while (0)
# else
#  define DEBUG_LOG(msg) do {} while (0)
# endif

/* ===== ANSI COLOR CODES ===== */
# define RESET "\033[0m"
# define CONSTRUCTOR_COLOR "\033[36m"
# define DESTRUCTOR_COLOR "\033[35m"
# define ERROR_COLOR "\033[91m"

# if DEBUG == 1
#  define DEBUG_ERROR(msg) do { \
		std::cerr << ERROR_COLOR << msg << RESET << std::endl; } while (0)
# else
#  define DEBUG_ERROR(msg) do {} while (0)
# endif

/* ===== BASE EXCEPTION ===== */

class PmergeMeExceptions : public std::exception
{
	protected:
		std::string _message;
	
	public:
		PmergeMeExceptions(void);
		PmergeMeExceptions(const PmergeMeExceptions &other);
		PmergeMeExceptions &operator=(const PmergeMeExceptions &other);
		virtual ~PmergeMeExceptions(void) throw();

		virtual const char	*what(void) const throw();
};

/* ===== EXCEPTIONS ===== */

class InputException : public PmergeMeExceptions
{
	public:
		InputException(const std::string &invalidArg);
		~InputException(void) throw();
};

class NegativeNumberException : public PmergeMeExceptions
{
	public:
		NegativeNumberException(void);
		~NegativeNumberException(void) throw();
};

class InvalidSequenceException : public PmergeMeExceptions
{
	public:
		InvalidSequenceException(const std::string &msg);
		~InvalidSequenceException(void) throw();
};

/* ===== FORD JOHNSON ALGORITHM ===== */

template<typename Container>
class PmergeMe
{
private:
	std::vector<int>	_generateJacobsthal(int max_value);

	void				_pairingPhase(Container &input, Container &larger, Container &smailler, int &oddElement);
	void				_recursiveSort(Container &larger);
	void				_insertionPhase(Container &sorted, const Container &smaller, const Container &partners, int oddElement);

	
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe(void);
	
	void	sort(Container &data);
};

#endif