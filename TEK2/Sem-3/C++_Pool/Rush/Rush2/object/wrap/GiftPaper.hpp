/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** GiftPaper.hpp
*/

#ifndef GIFT_PAPER_HPP_
    #define GIFT_PAPER_HPP_

    #include "Wrap.hpp"

    class GiftPaper : virtual public Wrap
    {
        public:
            GiftPaper(const std::string &title);
            GiftPaper(const Object &obj);
            ~GiftPaper();
    };

#endif