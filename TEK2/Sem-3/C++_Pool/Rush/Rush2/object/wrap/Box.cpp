/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** Box.cpp
*/

#include "Box.hpp"

Box::Box(const std::string &title):
    Object(title), Wrap(title)
{
    this->_type = "Box";
}

Box::Box(const Object &obj):
    Object(obj.getTitle()), Wrap(obj.getTitle())
{
    this->_type = "Box";
}

Box::~Box(void)
{
    if (this->_content)
        delete(this->_content);
}

Object *Box::getContent(void)
{
    if (this->_isOpen) {
        Object *cntnt = this->_content;
        this->_content = nullptr;
        cntnt->isTaken();
        return (cntnt);
    }
    std::cerr << "Box is closed." << ENDL;
    return (nullptr);
}

bool Box::wrapMeThat(Object *obj)
{
    if (!this->_isOpen) {
        std::cerr << "Box is closed." << ENDL;
        return (false);
    }
    if (this->_content) {
        std::cerr << "Wrap titled " << this->_title << " of type " << this->_type
        << " already contains an object titled " << this->_content->getTitle() << " of type "
        << this->_content->getType() << "." << ENDL;
        return (false);
    }
    this->_content = obj;
    return (true);
}