/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:23:51 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 11:23:52 by erico-ke         ###   ########.fr       */
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
        void    setname(std::string name);
        Zombie(std::string zName);
        ~Zombie(void);
};
    
Zombie  *zombieHorde(int N, std::string name);

#endif