/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:19:21 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/09 20:27:04 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main(void)
{
    std::cout << "Test 1: Basic Example from Exercise" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    
    std::cout << "\nTest 2: Stack Compatibility" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        
        std::stack<int> s(mstack);
        std::cout << "Standard stack top: " << s.top() << std::endl;
        std::cout << "Standard stack size: " << s.size() << std::endl;
    }
    
    std::cout << "\nTest 3: Comparison with std::list" << std::endl;
    {
        std::cout << "MutantStack output:" << std::endl;
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << std::endl;
        
        std::cout << "\nstd::list output (push_back instead of push):" << std::endl;
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);
        
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
            std::cout << *it << std::endl;
    }
    
    std::cout << "\nTest 4: Reverse Iterators" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(100);
        mstack.push(200);
        mstack.push(300);
        
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
            std::cout << *it << std::endl;
    }
    
    std::cout << "\nTest 5: Pre-increment and Pre-decrement" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        mstack.push(40);
        
        MutantStack<int>::iterator it = mstack.begin();
        std::cout << "First element: " << *it << std::endl;
        ++it;
        std::cout << "Second element: " << *it << std::endl;
        ++it;
        ++it;
        std::cout << "Fourth element: " << *it << std::endl;
        --it;
        std::cout << "After decrement: " << *it << std::endl;
    }
    
    std::cout << "\nTest 6: Empty Stack" << std::endl;
    {
        MutantStack<int> mstack;
        std::cout << "Empty stack size: " << mstack.size() << std::endl;
        std::cout << "Is empty: " << (mstack.empty() ? "yes" : "no") << std::endl;
        
        mstack.push(42);
        std::cout << "After push, is empty: " << (mstack.empty() ? "yes" : "no") << std::endl;
        mstack.pop();
        std::cout << "After pop, is empty: " << (mstack.empty() ? "yes" : "no") << std::endl;
    }
    
    std::cout << "\nTest 7: Complex Operations" << std::endl;
    {
        MutantStack<int> mstack;
        for (int i = 1; i <= 10; ++i)
            mstack.push(i * 10);
        
        std::cout << "Stack contents (forward):" << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        
        std::cout << "Stack contents (reverse):" << std::endl;
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    
    std::cout << "\nTest 8: Const Iterators" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(10);
        mstack.push(15);
        
        const MutantStack<int> const_mstack = mstack;
        for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
            std::cout << *it << std::endl;
    }
    
    return 0;
}