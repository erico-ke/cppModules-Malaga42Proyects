/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:54:43 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/01 13:45:36 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"

static void	printSection(const std::string &title)
{
	std::cout << "\n" << GREEN << "===== " << title << " =====" << RESET << std::endl;
}

static void	printStats(const Bureaucrat &b, const AForm &f1, const AForm &f2, const AForm &f3)
{
	std::cout << GREEN << "=== INITIAL STATISTICS ===" << RESET << std::endl;
	std::cout << b.getName() << " (Chief) - Grade: " << b.getGrade() << std::endl;
	std::cout << f1.getName() << " - Sign Grade: " << f1.getSignGrade() 
		<< ", Execute Grade: " << f1.getExecuteGrade() 
		<< ", Signed: " << (f1.getIsSigned() ? "Yes" : "No") << std::endl;
	std::cout << f2.getName() << " - Sign Grade: " << f2.getSignGrade() 
		<< ", Execute Grade: " << f2.getExecuteGrade() 
		<< ", Signed: " << (f2.getIsSigned() ? "Yes" : "No") << std::endl;
	std::cout << f3.getName() << " - Sign Grade: " << f3.getSignGrade() 
		<< ", Execute Grade: " << f3.getExecuteGrade() 
		<< ", Signed: " << (f3.getIsSigned() ? "Yes" : "No") << std::endl;
}

static void	tryExecute(const Bureaucrat &executor, const AForm &form)
{
	std::cout << executor.getName() << " tries to execute "
		<< form.getName() << " -> ";
	try
	{
		form.execute(executor);
		std::cout << "OK" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}

int	main(void)
{
	try
	{
		Bureaucrat	chief("Chief", 1);
		Bureaucrat	junior("Junior", 70);
		Bureaucrat	intern("Intern", 150);

		ShrubberyCreationForm	shrub("garden");
		RobotomyRequestForm		robot("Bender");
		PresidentialPardonForm	pardon("Ford Prefect");
		
		if (DEBUG == 1)
		printStats(chief, shrub, robot, pardon);

		printSection("UNSIGNED EXECUTION ATTEMPT");
		tryExecute(chief, shrub);
		tryExecute(chief, robot);
		tryExecute(chief, pardon);

		printSection("SIGN ATTEMPT WITH INSUFFICIENT GRADE");
		intern.signForm(shrub);
		intern.signForm(robot);
		intern.signForm(pardon);

		printSection("SUCCESSFUL SIGNATURE");
		chief.signForm(shrub);
		chief.signForm(robot);
		chief.signForm(pardon);

		printSection("SIGNED EXECUTION WITH INSUFFICIENT GRADE");
		tryExecute(intern, shrub);
		tryExecute(junior, robot);
		tryExecute(junior, pardon);

		printSection("SIGNED EXECUTION WITH SUFFICIENT GRADE");
		tryExecute(chief, shrub);
		tryExecute(chief, robot);
		tryExecute(chief, pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Main error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}