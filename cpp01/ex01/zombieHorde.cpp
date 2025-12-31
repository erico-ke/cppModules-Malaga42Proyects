#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *Horde = new Zombie[N];

    int i = -1;
    while (++i < N)
        Horde[i].setname(name);
    return Horde;
}