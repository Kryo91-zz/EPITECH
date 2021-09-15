/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD14M-corentin.petrau
** File description:
** main.cpp
*/

#include "ex00/Fruit.hpp"
#include "ex00/Lemon.hpp"
#include "ex00/Banana.hpp"
#include "ex00/FruitBox.hpp"
#include "ex00/FruitNode.hpp"

int main(void)
{
    FruitBox box(5);
    Fruit *f1 = new Banana;
    Fruit *f2 = new Lemon;
    Fruit *f3 = new Lemon;

    COUT << std::boolalpha << box.putFruit(f1) << ENDL;
    COUT << std::boolalpha << box.putFruit(f2) << ENDL;
    COUT << std::boolalpha << box.putFruit(f3) << ENDL;
    COUT << box.nbFruits() << ENDL;
    Fruit *f = box.pickFruit();
    COUT << "Fruit: " << f1->getName() << ", " << f1->getVitamins() << ENDL;
    COUT << box.nbFruits() << ENDL;
    FruitNode *list_head __attribute__((unused)) = box.head();

    delete f1;
    return 0;
}