/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** Wrap.cpp
*/

#include "Wrap.hpp"
#include "../toy/Teddy.hpp"
#include "../toy/LittlePony.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"

Wrap::Wrap(const std::string &title):
    Object(title)
{
    this->_type = "Wrap";
}

Wrap::~Wrap(void)
{
}

void Wrap::openMe(void)
{
    this->_isOpen = true;
}

void Wrap::closeMe(void)
{
    this->_isOpen = false;
}

Object *Wrap::getContent(void)
{
    Object *cntnt = this->_content;

    cntnt->isTaken();
    this->_content = nullptr;
    return (cntnt);
}

bool Wrap::wrapMeThat(Object *obj)
{
    if (this->_content) {
        std::cerr << "Wrap titled " << this->_title << " of type " << this->_type
        << " already contains an object titled " << this->_content->getTitle() << " of type "
        << this->_content->getType() << "." << ENDL;
        return (false);
    }
    this->_content = obj;
    return (true);
}

Object *MyUnitTests(Object **start_objects)
{
    Teddy *ted = dynamic_cast<Teddy *>(start_objects[0]);
    Box *box = dynamic_cast<Box *>(start_objects[1]);
    GiftPaper *paper = dynamic_cast<GiftPaper *>(start_objects[2]);

    box->openMe();
    box->wrapMeThat(ted);
    box->closeMe();
    paper->wrapMeThat(box);
    return (paper);
}