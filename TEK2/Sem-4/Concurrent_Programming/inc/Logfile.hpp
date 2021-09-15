/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Logfile
*/

#pragma once

#include "inc.hpp"

class Logfile
{
    public:
        Logfile();
        ~Logfile();
        void LMessage(std::string message);
        std::string currentDateTime();
        void CommandMessage();
        void EndCommandMessage();

    protected:
    private:
        std::ofstream _stream;
};
