#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}

Zombie::Zombie(std::string zName) : name(zName)
{
    return ;
}

Zombie::~Zombie()
{
    std::cout << this ->name << " was erased from existance." << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}