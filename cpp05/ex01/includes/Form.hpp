/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:04:18 by erico-ke          #+#    #+#             */
/*   Updated: 2026/03/31 18:12:23 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;
public:
	Form(void);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form(void);
	
	class	GradeTooHighException : public std::exception
	{
	public:
		const char	*what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
	public:
		const char	*what() const throw();
	};
	
	void	beSigned(const Bureaucrat &other);
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif