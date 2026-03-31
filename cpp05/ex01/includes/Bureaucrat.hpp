/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:08:35 by erico-ke          #+#    #+#             */
/*   Updated: 2026/03/31 18:14:03 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

# if DEBUG == 1
#  define DEBUG_LOG(msg) do { std::cout << msg << std::endl; } while (0)
# else
#  define DEBUG_LOG(msg) do {} while (0)
# endif

# define RESET "\033[0m"
# define CONSTRUCTOR_COLOR "\033[36m"
# define DESTRUCTOR_COLOR "\033[35m"

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat(void);
	
	void				incrementGrade();
	void				decrementGrade();

	const std::string	&getName() const;
	int					getGrade() const;

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

	void	signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);

#endif