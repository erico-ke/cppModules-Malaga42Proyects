/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:32:26 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/19 16:52:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RESET "\033[0m"
# define CONSTRUCTOR_COLOR "\033[36m"
# define DESTRUCTOR_COLOR "\033[35m"
# define SOUND_COLOR "\033[33m"

class Animal
{
protected:
	std::string _type;
public:
	Animal(void);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal(void);
	
	std::string		getType(void) const;
	virtual void	makeSound(void) const;
};

#endif