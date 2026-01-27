/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:16:51 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/27 16:31:31 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	~ScavTrap();

	ScavTrap	&operator=(const ScavTrap &other);
	
	void		guardGate(void);

	int			getHitPoints(void);
	int			getEnergyPoints(void);
	int			getAttackDamage(void);
	std::string	getName(void);
};

#endif