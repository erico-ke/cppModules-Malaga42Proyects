/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:17:37 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 14:23:09 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "./AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	~Ice(void);
	
	virtual AMateria	*clone() const;
	void				use(ICharacter &target);
};

#endif