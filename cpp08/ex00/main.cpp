/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:43:54 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/09 17:49:20 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
    std::cout << "=== easyfind Test Suite ===" << std::endl;
    
    // Test 1: Vector - element found
    std::cout << "\nTest 1: Vector with present element" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found: " << *it << " at position " 
                  << (it - vec.begin()) << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 2: Vector - element NOT found
    std::cout << "\nTest 2: Vector with absent element" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 999);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Correct exception: " << e.what() << std::endl;
    }
    
    // Test 3: List - element found
    std::cout << "\nTest 3: List with present element" << std::endl;
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    
    try
    {
        std::list<int>::iterator it = easyfind(lst, 200);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 4: List - element NOT found
    std::cout << "\nTest 4: List with absent element" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 555);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Correct exception: " << e.what() << std::endl;
    }

    return 0;
}

