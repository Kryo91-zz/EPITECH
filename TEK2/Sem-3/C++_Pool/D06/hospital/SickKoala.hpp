/*
** EPITECH PROJECT, 2020
** SickKoala.hpp
** File description:
** SickKoala
*/

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

class SickKoala
{
    private:
        std::string name;

    public:
        SickKoala(std::string name);
        ~SickKoala();
        void poke();
        bool takeDrug(std::string drug);
        void overDrive(std::string message);
};