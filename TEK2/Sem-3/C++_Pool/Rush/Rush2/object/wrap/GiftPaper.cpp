/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** GiftPaper.cpp
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper(const std::string &title):
    Object(title), Wrap(title)
{
    this->_type = "GiftPaper";
}

GiftPaper::GiftPaper(const Object &obj):
    Object(obj.getTitle()), Wrap(obj.getTitle())
{
    this->_type = "GiftPaper";
}

GiftPaper::~GiftPaper()
{
}