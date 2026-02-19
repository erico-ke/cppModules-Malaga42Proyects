/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:45:16 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/19 14:28:17 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define HIGHFIVE_COLOR "\033[34m"
# define WHAMM_COLOR "\033[5;93m"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	~FragTrap(void);

	FragTrap	&operator=(const FragTrap &other);

	void		attack(const std::string &target);
	void		highFivesGuys(void);
};


#endif