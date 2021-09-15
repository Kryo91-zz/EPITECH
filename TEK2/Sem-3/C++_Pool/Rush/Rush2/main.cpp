#include "object/Object.hpp"

// Object **MyUnitTests()
// {
//     Object **tab = new Object*[3];
//     LittlePony *pony = new LittlePony("happy pony");
//     Teddy *ted = new Teddy("cuddles");
//     tab[0] = pony;
//     tab[1] = ted;
//     tab[2] = nullptr;
//     return tab;
// }

int main(void)
{
    Object **tab = MyUnitTests();
    // Teddy roosevelt("roosevelt");
    // LittlePony MyLittlePony("axel");
    // tab[0] = &roosevelt;
    // tab[1] = &MyLittlePony;
    for (int i = 0; tab[i]; i++) {
        // COUT << tab[i]->getTitle() << ENDL;
        COUT << *tab[i];
        //tab[i]->isTaken();
        delete(tab[i]);
    }
    // tab[0]->isTaken();
    // roosevelt.isTaken();
    // MyLittlePony.isTaken();

    delete[] tab;
    return 0;
}