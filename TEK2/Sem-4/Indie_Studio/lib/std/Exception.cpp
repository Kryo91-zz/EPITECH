/*
** EPITECH PROJECT, 2020
** B-CCP-400-MPL-4-1-theplazza-alec.ferrari
** File description:
** Exception.cpp
*/

#include "lib/std/Exception.hpp"

namespace lib
{
    Exception::Exception(std::string msg):
        _msg("Error: " + msg)
    {}

    const char *Exception::what() const throw()
    {
        return this->_msg.c_str();
    }

} // namespace lib
