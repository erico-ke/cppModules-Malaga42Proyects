/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 14:55:41 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/20 10:34:05 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cctype>
# include <exception>
# include <climits>

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
class BitcoinExchangeException : public std::exception
{
	protected:
		std::string	_message;

	public:
		BitcoinExchangeException(const std::string& message);
		BitcoinExchangeException(const BitcoinExchangeException& other);
		BitcoinExchangeException&	operator=(const BitcoinExchangeException& other);
		virtual ~BitcoinExchangeException(void) throw();

		virtual const char*	what(void) const throw();
};

/* ===== DERIVED EXCEPTIONS ===== */

class FileException : public BitcoinExchangeException
{
	public:
		FileException(const std::string& filename);
		~FileException(void) throw();
};

class DateException : public BitcoinExchangeException
{
	public:
		DateException(const std::string& date);
		~DateException(void) throw();
};

class ValueException : public BitcoinExchangeException
{
	public:
		ValueException(const std::string& value, const std::string& reason);
		~ValueException(void) throw();
};

class InvalidFormatException : public BitcoinExchangeException
{
	public:
		InvalidFormatException(const std::string& line);
		~InvalidFormatException(void) throw();
};

/* ===== MAIN CLASS ===== */
class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;

		bool	_isValidDate(const std::string& date) const;
		bool	_isValidValue(const std::string& value) const;
		float	_parseFloat(const std::string& str) const;
		bool	_isNumber(const std::string& str) const;
		int		_parseInt(const std::string& str) const;
		bool	_isLeapYear(int year) const;
		float	_getExchangeRate(const std::string& date) const;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange(void);

		void	loadDatabase(const std::string& filename);
		void	processInput(const std::string& inputFile);
};

#endif

