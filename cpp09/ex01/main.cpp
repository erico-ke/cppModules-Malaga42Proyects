/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:56:08 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/20 14:49:02 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"

int	main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            std::cerr << ERROR_COLOR << "Error: usage: ./RPN [expression]" << RESET << std::endl;
            return 1;
        }
        
        RPN calculator;
        int result = calculator.processExpression(argv[1]);
        
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << ERROR_COLOR << e.what() << RESET << std::endl;
        return 1;
    }
    
    return 0;
}
