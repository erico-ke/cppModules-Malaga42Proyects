#include "Zombie.hpp"

int main(void)
{
    Zombie *Horde = zombieHorde(4, "Carlos");
   int i = 0;
   while (i < 4)
   {
        std::cout << i << " ";
        Horde[i].announce();
        i++;
   }
   delete[] Horde;
   return 0;
}