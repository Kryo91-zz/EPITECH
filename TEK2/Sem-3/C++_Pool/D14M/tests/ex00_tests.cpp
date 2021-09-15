/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD14M-alec.ferrari
** File description:
** ex00_tests.cpp
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include <cassert>
#include <assert.h>
#include <iostream>
#include "../ex00/FruitBox.hpp"
#include "../ex00/Banana.hpp"
#include "../ex00/Lemon.hpp"

Test(init_fruitBox, empty_init)
{
    FruitBox box(5);

    cr_assert(box.nbFruits() == 0, "nbFruits isn't == 0");
    cr_assert(box.head() == nullptr, "head isn't nullptr");
    cr_assert(box.pickFruit() == nullptr, "box.pickFruit isn't nullptr");
    cr_assert(box.nbFruits() == 0, "box.nbFruits() isn't 0");
}

Test(put_fruitBox, put_fruit)
{
    FruitBox box(2);
    Fruit *f = new Lemon;
    Fruit *f2 = new Banana;
    Fruit *f3 = new Banana;

    cr_assert(box.putFruit(f) == true, "box.putFruit(f) isn't true");
    cr_assert(box.nbFruits() == 1, "box.nbFruits() isn't 1");
    cr_assert(box.putFruit(f2) == true, "box.putFruit(f2) isn't true");
    cr_assert(box.nbFruits() == 2, "box.nbFruits() isn't 2");
    cr_assert(box.putFruit(f3) == false, "box.putFruit(f3) isn't false");
    cr_assert(box.nbFruits() == 2, "box.nbFruits() isn't 2");
}

Test(pick_fruitBox, pick_fruit)
{
    FruitBox box(2);
    Fruit *f = new Lemon;
    Fruit *f2 = new Banana;
    Fruit *tmp = nullptr;

    box.putFruit(f);
    box.putFruit(f2);
    tmp = box.pickFruit();
    cr_assert(box.nbFruits() == 1, "box.nbFruits() isn't 1");
    cr_assert(tmp == f, "tmp isn't f");
    tmp = box.pickFruit();
    cr_assert(box.nbFruits() == 0, "box.nbFruits() isn't 0");
    cr_assert(tmp == f2, "tmp isn't f2");
    cr_assert(box.pickFruit() == nullptr, "box.pickFruit() isn't nullptr");
    cr_assert(box.nbFruits() == 0, "box.nbFruits() isn't 0");

    delete(f);
    delete(f2);
}