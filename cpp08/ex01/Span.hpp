/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:55:01 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/09 18:09:59 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

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

class Span
{
private:
	unsigned int		_N;
	std::vector<int>	_numbers;
public:
	Span(void);
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span(void);
	
	void	addNumber(int num);
	int		shortestSpan(void) const;
	int		longuestSpan(void) const;

	class	NotEnoughSpace : public std::exception
	{
	public:
		const char	*what() const throw();
	};

	template<typename Iterator>
	void	addRange(Iterator first, Iterator last)
	{
		for (Iterator i = first; i != last; ++i)
		{
			try
			{
				this->addNumber(*i);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			
		}
	}

	unsigned int	getN(void) const;
	unsigned int	getSize(void) const;
};

#endif