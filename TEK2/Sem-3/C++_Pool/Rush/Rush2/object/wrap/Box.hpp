/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** Box.hpp
*/

#ifndef BOX_HPP_
    #define BOX_HPP_

    #include "Wrap.hpp"

    class Box : virtual public Wrap
    {
        public:
            Box(const std::string &title);
            Box(const Object &obj);
            ~Box();
            Object *getContent(void) override;
            bool wrapMeThat(Object *obj) override;
    };


#endif