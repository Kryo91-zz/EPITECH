/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Fantasia
*/

#include "../inc/Fantasia.hpp"

fantasia::fantasia(int fd, std::string size, double multiplier, std::chrono::milliseconds time)
{
    this->_bake = false;
    std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point r1 = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point r2 = std::chrono::system_clock::now();
    Ingredients ing;
    std::string tmp;

    while (this->_bake == false) {
        this->work_time = a - b;
        this->restock_time = r1 - r2;
        if (this->work_time.count() >= (4000.0 * multiplier) && ing.fantasia() == true) {
            tmp = "Fantasia " + size + " is done ";
            write(fd, tmp.c_str(), strlen(tmp.c_str()));
            tmp.clear();
            b = std::chrono::system_clock::now();
            this->_bake = true;
        } else {
                if (ing.check_fantasia() == false)
                    write(fd, "Not enough stock to bake your command please wait\n", 50);
            a = std::chrono::system_clock::now();
            this->work_time = a - b;
        }
        if (this->restock_time >= time) {
            ing.restock();
            r2 = std::chrono::system_clock::now();
        } else {
            r1 = std::chrono::system_clock::now();
            this->restock_time = r1 - r2;
        }
    }
}

fantasia::~fantasia()
{
}
