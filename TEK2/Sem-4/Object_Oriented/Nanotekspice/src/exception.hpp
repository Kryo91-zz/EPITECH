/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-tekspice-lyvia.mallereau
** File description:
** exception.hpp
*/

#include "../inc/lib_included.hpp"

namespace nts
{
    class Exception : public std::exception
    {
        public:
        Exception(std::string const &message);
        const char *what() const noexcept override { return this->_message.c_str(); }

        protected:
            std::string _message;
    };
} // namespace nts
