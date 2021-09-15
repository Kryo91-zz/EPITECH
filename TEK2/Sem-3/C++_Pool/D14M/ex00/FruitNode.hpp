/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD14M-corentin.petrau
** File description:
** FruitNode.hpp
*/

#ifndef FRUITNODE_HPP_
    #define FRUITNODE_HPP_

#include "Fruit.hpp"

typedef struct FruitNode_s FruitNode;

struct FruitNode_s
{
    Fruit *f;
    FruitNode *next;
};

#endif // !FRUITNODE_HPP_
