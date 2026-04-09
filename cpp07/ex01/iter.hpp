/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:06:18 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/09 13:13:47 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename F>
void	iter(T *array, const std::size_t len, F f)
{
		if (!array && len > 0)
			return ;
		for (std::size_t i = 0; i < len; i++)
			f(array[i]);
}

#endif