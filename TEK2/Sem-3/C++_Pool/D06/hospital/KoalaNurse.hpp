/*
** EPITECH PROJECT, 2020
** hospital
** File description:
** KoalaNurse.hpp
*/

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "SickKoala.hpp"

class KoalaNurse
{
    private:
        std::string id;

    public:
        KoalaNurse(std::string id);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *koala);
        std::string readReport(std::string filename);
};