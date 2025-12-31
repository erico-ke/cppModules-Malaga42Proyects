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