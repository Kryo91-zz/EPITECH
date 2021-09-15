/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** Wrap.hpp
*/

#ifndef WRAP_HPP_
    #define WRAP_HPP_

    #include "../Object.hpp"

    class Wrap : virtual public Object
    {
        protected:
            Object *_content = nullptr;
            bool _isOpen = false;
        public:
            Wrap(const std::string &title);
            ~Wrap();

            void wrapMeThat(Object *object) const;
            void openMe(void);
            void closeMe(void);
            virtual Object *getContent(void);
            virtual bool wrapMeThat(Object *obj);
    };

    Object *MyUnitTests(Object **start_objects);

#endif