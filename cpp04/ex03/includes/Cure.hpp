/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:12:23 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 15:13:33 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "./AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure(void);
	
	virtual AMateria	*clone() const;
	void				use(ICharacter &target);
};

#endif