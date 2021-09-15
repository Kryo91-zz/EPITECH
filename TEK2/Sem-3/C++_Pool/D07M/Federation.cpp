/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Federation.cpp
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    std::cout << "The ship USS " << this->_name.c_str() << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl; 
}

Federation::Starfleet::Ship::~Ship(void) {}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    if (this->_core != core) {
        if (this->_core)
            delete this->_core;
        this->_core = core;
    }
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    if (this->_core->checkReactor()->isStable())
        std::cout << "USS " << this->_name << ": The core is stable at the time." << std::endl; 
    else
        std::cout << "USS " << this->_name << ": The core is unstable at the time." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;
    std::cout << "The independent ship " << name.c_str() << " just finished its construction." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship(void){}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    if (this->_core != core) {
        if (this->_core)
            delete this->_core;
        this->_core = core;
    }
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore(void)
{
    if (this->_core->checkReactor()->isStable())
        std::cout << this->_name << ": The core is stable at the time." << std::endl; 
    else
        std::cout << this->_name << ": The core is unstable at the time." << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain() {}

std::string Federation::Starfleet::Captain::getName(void)
{
    return this->_name;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

int Federation::Starfleet::Captain::getAge(void)
{
    return this->_age;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS." << this->_name << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << this->_name.c_str() << ", awaiting orders." << std::endl;
}