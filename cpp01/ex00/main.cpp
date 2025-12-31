#include "Zombie.hpp"

int main(void)
{
    Zombie *Raul = newZombie("Raul");
    Raul->announce();
    randomChump("Joselito");
    delete Raul;
    return 0;
}
