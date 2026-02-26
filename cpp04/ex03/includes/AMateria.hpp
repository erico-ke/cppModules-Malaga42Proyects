/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:14:29 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 18:50:19 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

# define RESET "\033[0m"
# define CONSTRUCTOR_COLOR "\033[36m"
# define DESTRUCTOR_COLOR "\033[35m"
# define USE_COLOR "\033[33m"
# define ERROR_COLOR "\033[31m"

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria(void);

	std::string const	&getType() const;

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);
	
	
};

#endif