/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Kitchen
*/

#include "../inc/Kitchen.hpp"
#include "../inc/Margarita.hpp"
#include "../inc/Regina.hpp"
#include "../inc/Fantasia.hpp"
#include "../inc/Americana.hpp"

Kitchen::Kitchen(double multiplier, size_t nb_cook, std::chrono::milliseconds time)
{
    this->_cooking_time_multiplier = multiplier;
    this->_nb_cooks = nb_cook;
    this->_time = time;
    memset(&this->_addr, 0, sizeof(this->_addr));

    this->_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (this->_fd <= 0) {
        if (close(this->_fd) == -1)
            throw Exception("Socket called");
    }
    this->_addr.sun_family = AF_UNIX;
    strcpy(this->_addr.sun_path, "Pizzeria");
    this->len = sizeof(this->_addr);
    if (connect(this->_fd, (struct sockaddr *)&this->_addr, (socklen_t)len) < 0)
        throw Exception("connect");
}

void Kitchen::cooking(std::string pizza, std::string size_pizza)
{
    if (pizza == "margarita") {
        margarita mar(this->_fd, size_pizza, this->_cooking_time_multiplier, this->_time);
    } else if (pizza == "regina") {
        regina reg(this->_fd, size_pizza, this->_cooking_time_multiplier, this->_time);
    } else if (pizza == "americana") {
        americana ame(this->_fd, size_pizza, this->_cooking_time_multiplier, this->_time);
    } else if (pizza == "fantasia") {
        fantasia fant(this->_fd, size_pizza, this->_cooking_time_multiplier, this->_time);
    }
}
