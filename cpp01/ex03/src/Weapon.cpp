#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string typ) : type(typ){return ;}

Weapon::~Weapon(void){return ;}

std::string const &Weapon::getType(void)
{
    return this->type;
}

void    Weapon::setType(std::string type)
{
    this->type = type;
    return ;
}