/*
** EPITECH PROJECT, 2020
** SickKoala.cpp
** File description:
** sick koala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke() {
    std::cout << "Mr." << this->name << ": Gooeeeeerrk !!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug) {
    if (strcmp(drug.c_str(), "Mars") == 0)
        std::cout << "Mr." << this->name << ": Mars, and it kreogs!" << std::endl;
    else if (strcmp(drug.c_str(), "Kinder") == 0)
        std::cout << "Mr." << this->name << ": There is a toy inside!" << std::endl;
    else
        std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
        return false;
    return true;
}

void SickKoala::overDrive(std::string message) {

    int position;

    while ((position = message.find("Kreog!")) != std::string::npos)
        message.replace(position, 6, "1337!", 0, 5);
    std::cout << "Mr." << this->name << ": " << message << std::endl;
}