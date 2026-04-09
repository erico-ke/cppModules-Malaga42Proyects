/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:22:54 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/09 20:18:43 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

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

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	MutantStack(void) {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
	MutantStack &operator=(const MutantStack &other)
	{
		std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack(void) {}
	
	iterator	begin(void)
	{
		return this->c.begin();
	}
	
	iterator	end(void)
	{
		return this->c.end();
	}

	const_iterator	begin(void) const
	{
		return this->c.begin();
	}

	const_iterator	end(void) const
	{
		return this->c.end();
	}

	reverse_iterator rbegin(void)
	{
		return this->c.rbegin();
	}

	reverse_iterator rend(void)
	{
		return this->c.rend();
	}

	const_reverse_iterator rbegin(void) const
	{
		return this->c.rbegin();
	}

	const_reverse_iterator rend(void) const
	{
		return this->c.rend();
	}
};

#endif