/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:05:35 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/09 13:15:23 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElem(const T &x)
{
    std::cout << x << " ";
}

void incrementInt(int &x)
{
    ++x;
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    const std::size_t nNums = sizeof(nums) / sizeof(nums[0]);

    std::cout << "nums original: ";
    iter(nums, nNums, printElem<int>);
    std::cout << std::endl;

    iter(nums, nNums, incrementInt);

    std::cout << "nums incrementado: ";
    iter(nums, nNums, printElem<int>);
    std::cout << std::endl;

    const int cnums[] = {10, 20, 30};
    const std::size_t nCnums = sizeof(cnums) / sizeof(cnums[0]);

    std::cout << "const nums: ";
    iter(cnums, nCnums, printElem<int>);
    std::cout << std::endl;

    std::string words[] = {"hola", "42", "iter"};
    const std::size_t nWords = sizeof(words) / sizeof(words[0]);

    std::cout << "words: ";
    iter(words, nWords, printElem<std::string>);
    std::cout << std::endl;

    return 0;
}

