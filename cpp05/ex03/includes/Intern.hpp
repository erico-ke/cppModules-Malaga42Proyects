/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:03:49 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/01 14:29:35 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "../includes/AForm.hpp"
# include "../includes/PresidentialPardonForm.hpp"
# include "../includes/RobotomyRequestForm.hpp"
# include "../includes/ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
public:

	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();
	
	AForm	*makeForm(const std::string &formName, const std::string &target) const;
	
	class FormNotFoundException : public std::exception
	{
	public:
		const char	*what() const throw();
	};
};

#endif

