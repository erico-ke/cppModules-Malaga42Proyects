/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:30:37 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/20 18:58:50 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"
#include <ctime>
#include <iomanip>

int main(int argc, char **argv)
{
    try
    {
        // Validar argumentos
        if (argc < 2)
        {
            std::cerr << "Error: Invalid input arguments" << std::endl;
            return 1;
        }
        
        // Leer datos
        std::deque<int> dataDeque;
        std::vector<int> dataVector;
        
        for (int i = 1; i < argc; ++i)
        {
            long value = std::strtol(argv[i], NULL, 10);
            
            if (value < 0)
            {
                std::cerr << "Error: Negative numbers not allowed" << std::endl;
                return 1;
            }
            
            dataDeque.push_back(static_cast<int>(value));
            dataVector.push_back(static_cast<int>(value));
        }
        
        // Mostrar entrada
        std::cout << "Before: ";
        for (size_t i = 0; i < dataDeque.size(); ++i)
            std::cout << dataDeque[i] << " ";
        std::cout << std::endl;
        
        // Ordenar con deque
        std::clock_t start_deque = std::clock();
        PmergeMe<std::deque<int> > pmergeDeque;
        pmergeDeque.sort(dataDeque);
        std::clock_t end_deque = std::clock();
        
        // Ordenar con vector
        std::clock_t start_vector = std::clock();
        PmergeMe<std::vector<int> > pmergeVector;
        pmergeVector.sort(dataVector);
        std::clock_t end_vector = std::clock();
        
        // Mostrar salida
        std::cout << "After: ";
        for (size_t i = 0; i < dataDeque.size(); ++i)
            std::cout << dataDeque[i] << " ";
        std::cout << std::endl;
        
        // Mostrar timing (máxima precisión)
        double time_deque = double(end_deque - start_deque) / CLOCKS_PER_SEC;
        double time_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC;
        
        std::cout << "Time to process a range of " << dataDeque.size()
                  << " elements with std::deque: "
                  << std::fixed << std::setprecision(5) << time_deque << " us" << std::endl;
        
        std::cout << "Time to process a range of " << dataVector.size()
                  << " elements with std::vector: "
                  << std::fixed << std::setprecision(5) << time_vector << " us" << std::endl;
        
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}