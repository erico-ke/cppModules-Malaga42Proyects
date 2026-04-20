/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:56:08 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/20 14:46:28 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ===== RPN_EXCEPTION IMPLEMENTATIONS ===== */

RPN_Exception::RPN_Exception(const std::string &message) : _message(message)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "RPN_Exception created" << RESET);
}

RPN_Exception::RPN_Exception(const RPN_Exception &other) : _message(other._message)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "RPN_Exception copied" << RESET);
}

RPN_Exception &RPN_Exception::operator=(const RPN_Exception &other)
{
	if (this != &other)
		_message = other._message;
	return *this;
}

RPN_Exception::~RPN_Exception(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "RPN_Exception destroyed" << RESET);
}

const char *RPN_Exception::what(void) const throw()
{
	return _message.c_str();
}

/* ===== TOKENEXCEPTION IMPLEMENTATIONS ===== */

TokenException::TokenException(const std::string &token) : RPN_Exception("")
{
	_message = "Error: invalid token:" + token;
	DEBUG_LOG(CONSTRUCTOR_COLOR << "TokenException created" << RESET);
}

TokenException::~TokenException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "TokenException destroyed" << RESET);
}

/* ===== STACKUNDERFLOWEXCEPTION IMPLEMENTATIONS ===== */

StackUnderflowException::StackUnderflowException(const std::string &message) : RPN_Exception(message)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "StackUnderflowException created" << RESET);
}

StackUnderflowException::~StackUnderflowException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "StackUnderflowException destroyed" << RESET);
}

/* ===== DIVISIONBYZEROEXCEPTION IMPLEMENTATIONS ===== */

DivisionByZeroException::DivisionByZeroException(const std::string &message) : RPN_Exception(message)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "DivisionByZeroException created" << RESET);
}

DivisionByZeroException::~DivisionByZeroException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "DivisionByZeroException destroyed" << RESET);
}

/* ===== SYNTAXEXCEPTION IMPLEMENTATIONS ===== */

SyntaxException::SyntaxException(const std::string &message) : RPN_Exception(message)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "SyntaxException created" << RESET);
}

SyntaxException::~SyntaxException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "SyntaxException destroyed" << RESET);
}

/* ===== TOOMANYUMBERSEXCEPTION IMPLEMENTATIONS ===== */

InvalidRangeOfNumberException::InvalidRangeOfNumberException(const std::string &message) : RPN_Exception(message)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "InvalidRangeOfNumberException created" << RESET);
}

InvalidRangeOfNumberException::~InvalidRangeOfNumberException(void) throw()
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "InvalidRangeOfNumberException destroyed" << RESET);
}

/* ===== RPN IMPLEMENTATIONS ===== */

RPN::RPN(void)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "RPN created" << RESET);
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
	DEBUG_LOG(CONSTRUCTOR_COLOR << "RPN copied" << RESET);
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN(void)
{
	DEBUG_LOG(DESTRUCTOR_COLOR << "RPN destroyed" << RESET);
}

/* ===== RPN METHODS ===== */

void RPN::validateExpression(const std::string &expression)
{
	if (expression.empty())
		throw SyntaxException("Empty expression.");
	
	std::stringstream	ss(expression);
	std::string			token;

	while (ss >> token)
	{
		if (_isNumber(token))
		{
			int	num = std::atoi(token.c_str());
			if (num < 0 || num > 9)
				throw InvalidRangeOfNumberException("Error : numbers must be between 0 and 9");
		}
		else if (!_isOperator(token))
			throw TokenException(token);
	}

	DEBUG_LOG("Expression " << expression << " validated.");
}

int RPN::processExpression(const std::string &expression)
{
	validateExpression(expression);

	while (!_stack.empty())
		_stack.pop();
	
	std::stringstream	ss(expression);
	std::string			token;

	while (ss >> token)
	{
		if (_isNumber(token))
		{
			_stack.push(_parseNumber(token));
			DEBUG_LOG("Pushed: " << token);
		}
		else if (_isOperator(token))
		{
			Operands ops = _popOperands();
			int result = _calculate(ops.first, ops.second, token[0]);
			_stack.push(result);
			DEBUG_LOG("Calculated: " << ops.first << " " << token << " " << ops.second << " = " << result);
		}
	}
	
	if (_stack.size() != 1)
		throw SyntaxException("Invalid expression");
	return _stack.top();
}

bool RPN::_isOperator(const std::string &token) const
{
	return (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'));
}

bool RPN::_isNumber(const std::string &token) const
{
	if (token.empty())
		return false;

	for (size_t i = 0; i < token.length(); ++i)
    {
        if (!std::isdigit(token[i]))
            return false;
    }
    return true;
}

int RPN::_parseNumber(const std::string &token) const
{
	if (!_isNumber(token))
        throw TokenException("Invalid number. Numbers must be between 0 and 9");
    
    char* endptr;
    long value = std::strtol(token.c_str(), &endptr, 10);
    
    if (*endptr != '\0' || value < 0 || value > 9)
        throw TokenException("Invalid number. Numbers must be between 0 and 9");
    
    return static_cast<int>(value);
}

int RPN::_calculate(int first, int second, char op) const
{
	switch (op)
	{
		case '+':
			return first + second;
		case '-':
			return first - second;
		case '*':
			return first * second;
		case '/':
			if (second == 0)
				throw DivisionByZeroException("Division by zero");
			return first / second;
		default:
			throw TokenException("Unknown operator");
	}
}

RPN::Operands RPN::_popOperands(void)
{
	if (_stack.size() < 2)
		throw StackUnderflowException("Not enough operands");
	Operands ops;
	ops.second = _stack.top();
	_stack.pop();
	ops.first = _stack.top();
	_stack.pop();

	DEBUG_LOG("Popped: " << ops.first << " and " << ops.second);
	
	return ops;
}