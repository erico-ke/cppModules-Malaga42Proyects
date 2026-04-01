/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:10:00 by copilot           #+#    #+#             */
/*   Updated: 2026/04/01 11:15:30 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef DEBUG_LOG
#  if DEBUG == 1
#   define DEBUG_LOG(msg) do { std::cout << msg << std::endl; } while (0)
#  else
#   define DEBUG_LOG(msg) do {} while (0)
#  endif
# endif

# ifndef RESET
#  define RESET "\033[0m"
# endif

# ifndef CONSTRUCTOR_COLOR
#  define CONSTRUCTOR_COLOR "\033[36m"
# endif

# ifndef DESTRUCTOR_COLOR
#  define DESTRUCTOR_COLOR "\033[35m"
# endif

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

protected:
	virtual void	executeAction(void) const = 0;

public:
	AForm(void);
	AForm(const std::string &name, int signGrade, int executeGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm(void);

	const std::string	&getName(void) const;
	bool				getIsSigned(void) const;
	int					getSignGrade(void) const;
	int					getExecuteGrade(void) const;

	void	beSigned(const Bureaucrat &other);
	void	execute(Bureaucrat const &executor) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		const char	*what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &src);

#endif
