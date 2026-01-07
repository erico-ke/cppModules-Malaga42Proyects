/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:23:35 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 11:23:36 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class   Zombie{
    private:
        std::string name;
    public:
        Zombie(void);
        void    announce(void);
        Zombie(std::string zName);
        ~Zombie(void);
};
    
void    randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif