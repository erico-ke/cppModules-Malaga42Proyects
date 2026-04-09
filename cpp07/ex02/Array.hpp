/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you                                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09                                 #+#    #+#             */
/*   Updated: 2026/04/09                                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>

#if DEBUG
# include <iostream>
# define DEBUGLOG std::cout
#else
# define DEBUGLOG if (0) std::cout
#endif

template <typename T>
class Array
{
private:
    T*              _data;
    unsigned int    _size;

public:
    Array(void);
    explicit Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;
};

# include "Array.tpp"

#endif