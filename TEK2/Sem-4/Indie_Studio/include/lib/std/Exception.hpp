/*
** EPITECH PROJECT, 2020
** B-CCP-400-MPL-4-1-theplazza-alec.ferrari
** File description:
** lib/Exception.hpp
*/

#pragma once

#include <exception>
#include <string>

namespace lib
{
    class Exception : public std::exception
    {
        private:
            std::string _msg;
        public:
            Exception(std::string msg);
            ~Exception(void) = default;
            const char *what() const throw();
    };
}