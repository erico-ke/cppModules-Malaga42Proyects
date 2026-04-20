/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 14:56:08 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/20 15:21:11 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//contenedor stack

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <exception>
# include <cctype>
# include <cstdlib>

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
class RPN_Exception : public std::exception
{
	protected:
		std::string _message;
	
	public:
		RPN_Exception(const std::string &message);
		RPN_Exception(const RPN_Exception &other);
		RPN_Exception	&operator=(const RPN_Exception &other);
		virtual	~RPN_Exception(void) throw();

		virtual const char	*what(void) const throw();
};

/* ===== EXCEPTIONS ===== */

class TokenException : public RPN_Exception
{
	public:
		TokenException(const std::string &token);
		~TokenException(void) throw();
};

class StackUnderflowException : public RPN_Exception
{
	public:
		StackUnderflowException(const std::string &message);
		~StackUnderflowException(void) throw();
};

class DivisionByZeroException : public RPN_Exception
{
	public:
		DivisionByZeroException(const std::string &message);
		~DivisionByZeroException(void) throw();
};

class SyntaxException : public RPN_Exception
{
	public:
		SyntaxException(const std::string &message);
		~SyntaxException(void) throw();
};

class InvalidRangeOfNumberException : public RPN_Exception
{
	public:
		InvalidRangeOfNumberException(const std::string &message);
		~InvalidRangeOfNumberException(void) throw();
};

/* ===== REVERSE POLISH CALCULATOR ===== */

class RPN
{
private:
	std::stack<int>	_stack;

	struct Operands
	{
		int	first;
		int second;
	};

	bool		_isOperator(const std::string &token) const;
	bool		_isNumber(const std::string &token) const;
	int			_parseNumber(const std::string &token) const;
	int			_calculate(int first, int second, char op) const;
	Operands	_popOperands(void);
public:
	RPN(void);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN(void);
	
	void	validateExpression(const std::string &expression);
	int		processExpression(const std::string &expression);
};

#endif