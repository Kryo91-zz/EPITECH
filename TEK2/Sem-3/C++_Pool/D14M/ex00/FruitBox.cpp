/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD14M-corentin.petrau
** File description:
** FruitBox.cpp
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size):
    _capacity(size) { }

FruitBox::~FruitBox() 
{
    FruitNode *curr = this->_head;

    while (this->_head) {
        this->_head = this->_head->next;
        delete curr->f;
        delete curr;
        curr = this->_head;
    }
}

int FruitBox::nbFruits() const
{
    return this->_nbFruit;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *curr = this->_head;

    if (this->_nbFruit+1 > this->_capacity)
        return false;

    while (curr && curr->next) {
        if (curr->f == f)
            return false;
        curr = curr->next;
    }

    FruitNode *new_fruit_node = new FruitNode;
    new_fruit_node->f = f;
    new_fruit_node->next = nullptr;
    if (!curr) {
        this->_head = new_fruit_node;
        this->_nbFruit += 1;
        return true;
    }
    curr->next = new_fruit_node;
    this->_nbFruit += 1;
    return true;
}

Fruit *FruitBox::pickFruit()
{
    if (!this->_head)
        return nullptr;
    FruitNode *tmp = this->_head;
    Fruit *tmp2 =this->_head->f;
    this->_head = this->_head->next;
    this->_nbFruit -= 1;
    delete(tmp);
    return tmp2;
}

FruitNode *FruitBox::head() const
{
    return this->_head;
}

