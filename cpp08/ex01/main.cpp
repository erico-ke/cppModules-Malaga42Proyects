/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:50:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/09 19:16:35 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "./Span.hpp"

void printSection(const std::string &title)
{
    std::cout << "\n" << "=== " << title << " ===" << std::endl;
}

int main(void)
{
    srand(time(NULL));
    
    // Test 1: Basic test from exercise
    printSection("Test 1: Basic Example from Exercise");
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longuestSpan() << std::endl;
    }
    
    // Test 2: Test with iterators (STL container)
    printSection("Test 2: Adding Numbers with Iterator Range");
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(10);
        vec.push_back(7);
        
        Span sp = Span(10);
        sp.addRange(vec.begin(), vec.end());
        
        std::cout << "Added 5 numbers via iterators" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longuestSpan() << std::endl;
    }
    
    // Test 3: Test with 10,000 numbers
    printSection("Test 3: Large Span with 10,000 Random Numbers");
    {
        Span sp = Span(10000);
        std::vector<int> large_vec;
        
        for (int i = 0; i < 10000; ++i)
            large_vec.push_back(rand() % 100000);
        
        sp.addRange(large_vec.begin(), large_vec.end());
        
        std::cout << "Added 10,000 random numbers" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longuestSpan() << std::endl;
    }
    
    // Test 4: Edge cases - empty span
    printSection("Test 4: Edge Case - Empty Span");
    {
        Span sp = Span(5);
        try
        {
            sp.shortestSpan();
        }
        catch (const std::logic_error &e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
    
    // Test 5: Edge case - only 1 element
    printSection("Test 5: Edge Case - Single Element");
    {
        Span sp = Span(5);
        sp.addNumber(42);
        try
        {
            sp.shortestSpan();
        }
        catch (const std::logic_error &e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
    
    // Test 6: Span is full
    printSection("Test 6: Exceeding Maximum Capacity");
    {
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        try
        {
            sp.addNumber(4);
        }
        catch (const Span::NotEnoughSpace &e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
    
    // Test 9: addRange exceeding capacity (silent fail with try-catch)
    printSection("Test 7: addRange Exceeding Capacity");
    {
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i)
            vec.push_back(i * 10);
        
        Span sp = Span(5);
        sp.addRange(vec.begin(), vec.end());
        
        std::cout << "Attempted to add 10 numbers to Span of size 5" << std::endl;
        std::cout << "Current size: " << sp.getSize() << std::endl;
        std::cout << "Elements added before full: " << sp.getSize() << std::endl;
    }
    
    return 0;
}

