/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:08:35 by erico-ke          #+#    #+#             */
/*   Updated: 2026/03/27 12:58:33 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>

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

class Bureucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureucrat(void);
	Bureucrat(std::string name, int grade);
	Bureucrat(const Bureucrat &other);
	Bureucrat &operator=(const Bureucrat &other);
	~Bureucrat(void);
	
	void				incrementGrade();
	void				decrementGrade();

	const std::string	getName();
	int					getGrade();

	class	GradeTooHighExeption : public std::exception
	{
	public:
		const char	*what() const throw();
	};
	class	GradeTooLowExeption : public std::exception
	{
	public:
		const char	*what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const Bureucrat &src);

#endif