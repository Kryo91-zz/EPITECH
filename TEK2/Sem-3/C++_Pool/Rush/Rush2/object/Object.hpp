/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** Object.hpp
*/

#ifndef OBJECT_HPP_
    #define OBJECT_HPP_

    #include <iostream>

    #define COUT std::cout
    #define ENDL std::endl

    class Object
    {
        protected:
            std::string _title = "";
            std::string _type = "Object";
        public:
            Object(void);
            Object(const std::string &title);
            virtual ~Object();
            std::string getTitle(void) const { return this->_title; }
            std::string getType(void) const { return this->_type; }
            virtual void isTaken(void) const;
    };

    Object **MyUnitTests(void);
    std::ostream &operator<<(std::ostream &s, const Object &o);

#endif