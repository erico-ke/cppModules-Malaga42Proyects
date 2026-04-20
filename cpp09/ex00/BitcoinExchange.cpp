/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 14:55:39 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/20 12:49:26 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iomanip>

BitcoinExchangeException::BitcoinExchangeException(const std::string& message)
	: _message(message)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "BitcoinExchangeException created" << RESET);
}

BitcoinExchangeException::BitcoinExchangeException(const BitcoinExchangeException& other)
	: _message(other._message)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "BitcoinExchangeException copied" << RESET);
}

BitcoinExchangeException& BitcoinExchangeException::operator=(const BitcoinExchangeException& other)
{
	if (this != &other)
		_message = other._message;
	return *this;
}

BitcoinExchangeException::~BitcoinExchangeException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "BitcoinExchangeException destroyed" << RESET);
}

const char* BitcoinExchangeException::what(void) const throw()
{
	return _message.c_str();
}

FileException::FileException(const std::string& filename)
	: BitcoinExchangeException("")
{
	_message = "Error: could not open file " + filename;
	DEBUG_LOG(CONSTRUCTOR_COLOR << "FileException created" << RESET);
}

FileException::~FileException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "FileException destroyed" << RESET);
}

DateException::DateException(const std::string& date)
	: BitcoinExchangeException("")
{
	_message = "Error: bad input => " + date;
	DEBUG_LOG(CONSTRUCTOR_COLOR << "DateException created" << RESET);
}

DateException::~DateException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "DateException destroyed" << RESET);
}

ValueException::ValueException(const std::string& value, const std::string& reason)
	: BitcoinExchangeException("")
{
	(void)value;
	if (reason == "negative")
		_message = "Error: not a positive number.";
	else if (reason == "too_large")
		_message = "Error: too large a number.";
	DEBUG_LOG(CONSTRUCTOR_COLOR << "ValueException created" << RESET);
}

ValueException::~ValueException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "ValueException destroyed" << RESET);
}

InvalidFormatException::InvalidFormatException(const std::string& line)
	: BitcoinExchangeException("")
{
	_message = "Error: bad input => " + line;
	DEBUG_LOG(CONSTRUCTOR_COLOR << "InvalidFormatException created" << RESET);
}

InvalidFormatException::~InvalidFormatException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "InvalidFormatException destroyed" << RESET);
}

BitcoinExchange::BitcoinExchange(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "BitcoinExchange created" << RESET);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _database(other._database)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "BitcoinExchange copied" << RESET);
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "BitcoinExchange destroyed" << RESET);
}

bool BitcoinExchange::_isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::_isNumber(const std::string& str) const
{
	if (str.empty())
		return false;
	
	int dots = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			dots++;
			if (dots > 1)
				return false;
		}
		else if (!std::isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

int BitcoinExchange::_parseInt(const std::string& str) const
{
	long num = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str[i]))
		{
			num = num * 10 + (str[i] - '0');
			if (num > INT_MAX)
				return INT_MAX;
		}
	}
	return static_cast<int>(num);
}

float BitcoinExchange::_parseFloat(const std::string& str) const
{
	float value = 0.0f;
	size_t pos = str.find('.');
	
	if (pos != std::string::npos)
	{
		std::string intPart = str.substr(0, pos);
		std::string fracPart = str.substr(pos + 1);
		value = static_cast<float>(_parseInt(intPart));
		float frac = 0.0f;
		float divisor = 10.0f;
		for (size_t i = 0; i < fracPart.length(); i++)
		{
			frac += (fracPart[i] - '0') / divisor;
			divisor *= 10.0f;
		}
		value += frac;
	}
	else
	{
		value = static_cast<float>(_parseInt(str));
	}
	return value;
}

bool BitcoinExchange::_isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return false;
	
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	
	int year = _parseInt(date.substr(0, 4));
	int month = _parseInt(date.substr(5, 2));
	int day = _parseInt(date.substr(8, 2));
	
	if (month < 1 || month > 12)
		return false;
	
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (_isLeapYear(year))
		daysInMonth[1] = 29;
	
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	
	return true;
}

bool BitcoinExchange::_isValidValue(const std::string& value) const
{
	if (!_isNumber(value))
		return false;
	
	float fval = _parseFloat(value);
	
	if (fval < 0 || fval > 1000)
		return false;
	
	return true;
}

float BitcoinExchange::_getExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
	
	if (it != _database.end() && it->first == date)
		return it->second;
	
	if (it == _database.begin())
		return -1.0f;
	
	--it;
	return it->second;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	
	if (!file.is_open())
		throw FileException(filename);
	
	std::string line;
	std::getline(file, line);
	
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		
		size_t comma_pos = line.find(',');
		if (comma_pos == std::string::npos)
			continue;
		
		std::string date = line.substr(0, comma_pos);
		std::string rate_str = line.substr(comma_pos + 1);
		
		if (!_isValidDate(date))
		{
			DEBUG_ERROR("Invalid date in CSV: " << date);
			continue;
		}
		
		float rate = _parseFloat(rate_str);
		_database[date] = rate;
	}
	
	file.close();
	DEBUG_LOG("Loaded " << _database.size() << " entries from database");
}

void BitcoinExchange::processInput(const std::string& inputFile)
{
	std::ifstream file(inputFile.c_str());
	
	if (!file.is_open())
		throw FileException(inputFile);
	
	std::string line;
	std::getline(file, line);
	
	if (line != "date | value")
		throw InvalidFormatException(line);
	
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		
		try
		{
			size_t pipe_pos = line.find(" | ");
			if (pipe_pos == std::string::npos)
				throw InvalidFormatException(line);
			
			std::string date_str = line.substr(0, pipe_pos);
			std::string value_str = line.substr(pipe_pos + 3);
			
			if (!_isValidDate(date_str))
				throw DateException(date_str);
			
			if (!_isValidValue(value_str))
			{
				float fval = _parseFloat(value_str);
				if (fval < 0)
					throw ValueException(value_str, "negative");
				else
					throw ValueException(value_str, "too_large");
			}
			
			float rate = _getExchangeRate(date_str);
			if (rate < 0)
				continue;
			
			float value = _parseFloat(value_str);
			float result = value * rate;
			
			std::cout << date_str << " => " << value;
			std::cout << " = " << std::fixed << std::setprecision(2) << result << std::endl;
		}
		catch (const BitcoinExchangeException& e)
		{
			std::cerr << ERROR_COLOR << e.what() << RESET << std::endl;
		}
	}
	
	file.close();
}

