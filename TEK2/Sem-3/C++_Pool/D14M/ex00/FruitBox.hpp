/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD14M-corentin.petrau
** File description:
** FruitBox.hpp
*/

#ifndef FRUITBOX_HPP
    #define FRUTIBOX_HPP_


#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox
{
    public:
        FruitBox(int size);
        ~FruitBox();

        int nbFruits() const;
        bool putFruit(Fruit *f);
        FruitNode *head() const;
        Fruit *pickFruit();

        private:
            int _nbFruit = 0;
            int _capacity;
            FruitNode *_head = nullptr;

};

#endif // !FRUITBOX_HPP_