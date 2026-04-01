/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:54:43 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/01 12:47:24 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat	junior("Junior", 145);
			Bureaucrat	senior("Senior", 1);
			Form	easyForm("easyForm", 145, 145);
			Form	hardForm("hardForm", 1, 1);
			junior.signForm(easyForm);
			junior.signForm(hardForm);
			std::cout << hardForm.getName() << " sign state is " << hardForm.getIsSigned() << std::endl;
			senior.signForm(hardForm);
			std::cout << hardForm.getName() << " sign state is " << hardForm.getIsSigned() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Form	tooHighGrade("tooHighGrade", 0, 0);	
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form	tooLowGrade("tooLowGrade", 151, 151);	
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}