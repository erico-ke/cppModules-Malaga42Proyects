/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:02:48 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/20 15:35:55 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "./Animal.hpp"
# include "./Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat(void);
	
	virtual void	makeSound(void) const;
	std::string		getBrainIdea(int index) const;
	void			setBrainIdea(int index, const std::string &idea);
	const Brain*	getBrainAddress(void) const;
};

#endif