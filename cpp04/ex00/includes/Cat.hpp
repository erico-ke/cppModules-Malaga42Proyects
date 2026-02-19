/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:02:48 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/19 17:03:30 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "./Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat(void);
	
	virtual void	makeSound(void) const;
};

#endif