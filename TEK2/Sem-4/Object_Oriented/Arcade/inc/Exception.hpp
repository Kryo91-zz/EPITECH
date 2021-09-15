/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

class Exception : public std::exception 
{
    public:
        Exception(std::string const &message){this->_message = message;};
        const char *what() const noexcept override {return this->_message.c_str();}

    protected:
    std::string _message;
    private:
};

#endif /* !EXCEPTION_HPP_ */
