/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:55:33 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/23 15:13:31 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "./AAnimal.hpp"
# include "./Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog(void);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog(void);
	
	virtual void	makeSound(void) const;
	std::string		getBrainIdea(int index) const;
	void			setBrainIdea(int index, const std::string &idea);
	const Brain*	getBrainAddress(void) const;
};

#endif