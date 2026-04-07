/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:00:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/08 11:00:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static bool	isPseudoFloatLiteral(const std::string &literal)
{
	return (literal == "nanf" || literal == "+inff" || literal == "-inff");
}

static bool	isPseudoDoubleLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "+inf" || literal == "-inf");
}

static bool	isCharLiteral(const std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])));
}

static bool	isIntLiteral(const std::string &literal)
{
	char	*endptr;
	long	value;

	errno = 0;
	value = std::strtol(literal.c_str(), &endptr, 10);
	if (*endptr != '\0')
		return (false);
	if (errno == ERANGE)
		return (false);
	return (value >= std::numeric_limits<int>::min()
		&& value <= std::numeric_limits<int>::max());
}

static bool	isFloatLiteral(const std::string &literal)
{
	std::string	valuePart;
	char		*endptr;

	if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
		return (false);
	valuePart = literal.substr(0, literal.length() - 1);
	errno = 0;
	std::strtod(valuePart.c_str(), &endptr);
	if (*endptr != '\0')
		return (false);
	if (errno == ERANGE)
		return (false);
	return (valuePart.find('.') != std::string::npos);
}

static bool	isDoubleLiteral(const std::string &literal)
{
	char	*endptr;

	errno = 0;
	std::strtod(literal.c_str(), &endptr);
	if (*endptr != '\0')
		return (false);
	if (errno == ERANGE)
		return (false);
	return (literal.find('.') != std::string::npos);
}

static LiteralType	detectType(const std::string &literal)
{
	if (isPseudoFloatLiteral(literal))
		return (TYPE_PSEUDO_FLOAT);
	if (isPseudoDoubleLiteral(literal))
		return (TYPE_PSEUDO_DOUBLE);
	if (isCharLiteral(literal))
		return (TYPE_CHAR);
	if (isIntLiteral(literal))
		return (TYPE_INT);
	if (isFloatLiteral(literal))
		return (TYPE_FLOAT);
	if (isDoubleLiteral(literal))
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

static double	toDouble(const std::string &literal, LiteralType type)
{
	if (type == TYPE_CHAR)
		return (static_cast<double>(literal[0]));
	if (type == TYPE_INT)
		return (static_cast<double>(std::strtol(literal.c_str(), NULL, 10)));
	if (type == TYPE_FLOAT)
		return (std::strtod(literal.substr(0, literal.length() - 1).c_str(), NULL));
	if (type == TYPE_DOUBLE)
		return (std::strtod(literal.c_str(), NULL));
	if (literal == "nan" || literal == "nanf")
		return (std::numeric_limits<double>::quiet_NaN());
	if (literal == "+inf" || literal == "+inff")
		return (std::numeric_limits<double>::infinity());
	return (-std::numeric_limits<double>::infinity());
}

static void	printChar(double value)
{
	if (std::isnan(value) || std::isinf(value)
		|| value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char c = static_cast<char>(value);
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static void	printInt(double value)
{
	if (std::isnan(value) || std::isinf(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value)
{
	if (std::isnan(value))
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		std::cout << "float: " << (value < 0 ? "-inff" : "+inff") << std::endl;
		return ;
	}
	if (std::fabs(value) > std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	float f = static_cast<float>(value);
	std::cout << "float: " << std::fixed
		<< std::setprecision((f == static_cast<int>(f)) ? 1 : 6)
		<< f << "f" << std::endl;
}

static void	printDouble(double value)
{
	if (std::isnan(value))
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		std::cout << "double: " << (value < 0 ? "-inf" : "+inf") << std::endl;
		return ;
	}
	std::cout << "double: " << std::fixed
		<< std::setprecision((value == static_cast<int>(value)) ? 1 : 6)
		<< value << std::endl;
}

ScalarConverter::ScalarConverter(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "ScalarConverter default constructor called" << RESET);
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "ScalarConverter copy constructor called" << RESET);
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "ScalarConverter copy assignment operator called" << RESET);
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "ScalarConverter destructor called" << RESET);
}

void	ScalarConverter::convert(const std::string &literal)
{
	LiteralType	type;
	double		value;

	type = detectType(literal);
	if (type == TYPE_INVALID)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	value = toDouble(literal, type);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
