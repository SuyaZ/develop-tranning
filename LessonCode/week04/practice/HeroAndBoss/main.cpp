#include <iostream>
#include "Hero.h"
#include "Dragon.h"

int main()
{
    Dragon dragon;

    Hero A("A");
    Hero B("B");
    Hero C("C");

    dragon.Register(&A);
    dragon.Register(&B);
    dragon.Register(&C);

    dragon.Notify("the Dragon Boss is DEAD");

    
    return 0;
}
