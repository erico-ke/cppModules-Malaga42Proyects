/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:41:59 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/09 17:47:06 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>

template<typename T>
typename T::iterator	easyfind(T &a, int b)
{
    typename T::iterator i = std::find(a.begin(), a.end(), b);

    if (i == a.end())
        throw std::out_of_range("Element not found in the container");
    return i;
}

#endif