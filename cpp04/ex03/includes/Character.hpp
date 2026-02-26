/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:24:51 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 15:36:10 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "./ICharacter.hpp"
# include "./Ice.hpp"
# include "./Cure.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria	*_slot[4];
	AMateria	*_rest[500];
public:
	Character(void);
	Character(std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character(void);
	
	std::string const&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif