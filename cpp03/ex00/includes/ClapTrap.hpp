/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:36:40 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/19 13:39:29 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <fstream>
# include <cmath>

# define RESET "\033[0m"
# define CONSTRUCTOR_COLOR "\033[36m"
# define DESTRUCTOR_COLOR "\033[35m"
# define ATTACK_COLOR "\033[33m"
# define DAMAGE_COLOR "\033[31m"
# define HEAL_COLOR "\033[32m"

class ClapTrap
{
private:
	std::string			_name;
	unsigned int		_hitPoints;
	unsigned int		_energyPoints;
	unsigned int		_attackDamage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap(void);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
	std::string	getName(void);
};

#endif