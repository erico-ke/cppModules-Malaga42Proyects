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