/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-tekspice-lyvia.mallereau
** File description:
** Parser.hpp
*/

#pragma once

#include "../inc/lib_included.hpp"

namespace nts
{
    class Parser
    {
    private:
        std::string _line;
        bool valid = true;
    public:
        Parser(std::string file);
        ~Parser(){};
        std::vector<std::string> readfile(std::string filepath);
        std::vector <std::pair<std::string, std::string>> getchipsets(std::vector<std::string> tab);
        std::vector<std::pair<std::pair<std::string, int>, std::pair<std::string, int>>> getlinks(std::vector<std::string> tab);
    };

    class Exception : public std::exception
    {
        public:
        Exception(std::string const &message){this->_message = message;};
        const char *what() const noexcept override { return this->_message.c_str(); }

        protected:
            std::string _message;
    };
} // namespace nts
